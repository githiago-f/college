/*
 * Uma institui��o pode ter diversos recursos executando um mesmo ou mais tipos de programas
 * Talvez uma institui��o precise de um programa que renderize trabalhos 3D para uma impressora,
 * Talvez a mesma institui��o precise de um programa para compilar c�digo C.
 * Mas todas as institui��es devem se preocupar com o custo que ter uma m�quina online 24/7 pode 
 * trazer, nesse caso, as m�quinas ociosas (sem consumo por muito tempo) devem ser desligadas.
 * A ociosidade de programas tamb�m deve ser evitada, uma vez que um programa permanece inutilizado
 * por muito tempo, e sem comandos aguardando em sua fila, o sistema dever� parar a execu��o.
 * 
 */

-- buscar informa��es do aluno para login no sistema (filtrar por e-mail)
SELECT a.id_aluno, a.email, a.senha FROM alunos a WHERE a.email = 'email@email.com';

-- Verificar h� quanto tempo uma instancia n�o � utilizada.
SELECT 
    ins.id_instancia,
    round(to_number(sysdate - afi.terminou_em)*1440) as minutos_sem_uso 
FROM instancias ins 
JOIN aluno_fila_instancia afi ON afi.id_instancia = ins.id_instancia
ORDER BY afi.terminou_em DESC FETCH NEXT 1 ROWS ONLY;

-- Executar a mesma verifica��o pra todas as instancias de um recurso
SELECT
    re.id_recurso,
    ins.id_instancia,
    round(to_number(sysdate - (
        SELECT afi2.terminou_em 
        FROM aluno_fila_instancia afi2 
        WHERE afi2.id_instancia = ins.id_instancia
        ORDER BY afi2.terminou_em DESC
        FETCH NEXT 1 ROWS ONLY
    ))*1440)  as minutos_sem_uso
FROM recursos re
INNER JOIN instancias ins ON ins.id_recurso = re.id_recurso;

-- Pegar todos os recursos dispin�veis de uma institui��o (em_uso < capacidade)


-- Pegar instancias n�o utilizadas

-- Verificar quem executou um comando em determinado horario na instancia

-- Verificar as instancias rodando Java

-- Verificar numero de usu�rios na fila da instancia A

-- Determinar quantidade de mem�ria usada em um recurso
SELECT 
    re.id_recurso,
    SUM(pr.mem_consumida_apr) AS em_uso
FROM recursos re
INNER JOIN instancias ins ON ins.id_recurso = re.id_recurso
INNER JOIN programas pr ON pr.id_programa = ins.id_programa
GROUP BY re.id_recurso;
