/*
 * Uma instituição pode ter diversos recursos executando um mesmo ou mais tipos de programas
 * Talvez uma instituição precise de um programa que renderize trabalhos 3D para uma impressora,
 * Talvez a mesma instituição precise de um programa para compilar código C.
 * Mas todas as instituições devem se preocupar com o custo que ter uma máquina online 24/7 pode 
 * trazer, nesse caso, as máquinas ociosas (sem consumo por muito tempo) devem ser desligadas.
 * A ociosidade de programas também deve ser evitada, uma vez que um programa permanece inutilizado
 * por muito tempo, e sem comandos aguardando em sua fila, o sistema deverá parar a execução.
 * 
 */

-- 1 -> buscar informações do aluno para login no sistema (filtrar por e-mail)
SELECT a.id_aluno, a.email, a.senha FROM alunos a WHERE a.email = 'email@email.com';

-- 2 -> Verificar há quanto tempo uma instancia não é utilizada.
-- para fins de comparação, adicionei a coluna tempo_atual e ultimo_uso
SELECT 
    ins.id_instancia,
    to_char(afi.terminou_em, 'YYYY/MM/DD HH24:mi') ultimo_uso,
    to_char(sysdate, 'YYYY/MM/DD HH24:mi') tempo_atual,
    round(to_number(sysdate - afi.terminou_em)*1440) as minutos_sem_uso
FROM instancias ins 
JOIN aluno_fila_instancia afi ON afi.id_instancia = ins.id_instancia
WHERE ins.id_instancia = 1
ORDER BY afi.terminou_em DESC FETCH NEXT 1 ROWS ONLY;

-- 3 -> Executar a mesma verificação pra todas as instancias de um recurso
SELECT
    re.id_recurso,
    ins.id_instancia,
    round(to_number(sysdate - (
        SELECT afi2.terminou_em 
        FROM aluno_fila_instancia afi2 
        WHERE afi2.id_instancia = ins.id_instancia
        ORDER BY afi2.terminou_em DESC
        FETCH NEXT 1 ROWS ONLY
    ))*1440) as minutos_sem_uso
FROM recursos re
INNER JOIN instancias ins ON ins.id_recurso = re.id_recurso;

-- 4 -> Pegar todos os recursos dispiníveis de uma instituição
SELECT id_recurso FROM (
    SELECT 
        re.id_recurso,
        re.capacidade,
        COUNT(ins.id_instancia) AS instancias,
        SUM(pr.mem_consumida_apr) AS em_uso
    FROM recursos re
    LEFT JOIN instancias ins ON ins.id_recurso = re.id_recurso
    LEFT JOIN programas pr ON pr.id_programa = ins.id_programa
    GROUP BY re.id_recurso, re.capacidade
) WHERE em_uso < capacidade OR em_uso IS NULL;

-- 5 -> Pegar instancias não utilizadas REVISAR
SELECT 
    ins.id_instancia,
    COUNT(af.id_alunos_fila) AS alunos_na_fila
FROM instancias ins
JOIN filas fi ON fi.id_instancia = ins.id_instancia
LEFT JOIN alunos_fila af ON af.id_fila = fi.id_fila
WHERE af.data_saida IS NULL
GROUP BY fi.id_fila, ins.id_instancia
HAVING COUNT(af.id_alunos_fila) < 1;

-- 6 -> Verificar que comando foi executado e quem executou entre determinados 
-- horarios na instancia 1
SELECT 
    ins.id_instancia instancia, 
    af.id_usuario usuario, 
    comando 
FROM instancias ins
JOIN aluno_fila_instancia afi ON ins.id_instancia = afi.id_instancia
JOIN alunos_fila af ON afi.id_aluno_fila = af.id_alunos_fila
WHERE 
    (afi.iniciou_em BETWEEN to_date('11/06/2022 04:10', 'dd/mm/yyyy hh:mi') AND sysdate)
    AND ins.id_instancia = 1;

-- 7 -> Verificar as instancias rodando Java
SELECT ins.id_instancia FROM instancias ins
LEFT JOIN programas pr ON ins.id_instancia = pr.id_programa
WHERE pr.nome = 'Java';

-- 7 -> Verificar numero de usuários na fila da instancia (qualquer)
SELECT COUNT(*) as alunos_aguradando FROM alunos_fila af
JOIN filas fi ON fi.id_fila = af.id_fila
WHERE fi.id_instancia = 1 AND af.data_saida IS NULL;

-- 8 -> Determinar aproximadamente a quantidade de memória usada em um recurso
SELECT 
    re.id_recurso,
    SUM(pr.mem_consumida_apr) AS em_uso
FROM recursos re
INNER JOIN instancias ins ON ins.id_recurso = re.id_recurso
INNER JOIN programas pr ON pr.id_programa = ins.id_programa
GROUP BY re.id_recurso;
