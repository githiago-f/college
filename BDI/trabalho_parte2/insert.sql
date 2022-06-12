-- A instituição IFRS passou a utilizar a ferramenta:
INSERT INTO instituicoes VALUES (DEFAULT, 'IFRS');

-- Os hardwares a seguir estão conectados:
INSERT INTO recursos VALUES (DEFAULT, 8000, 1);
INSERT INTO recursos VALUES (DEFAULT, 8000, 1);
INSERT INTO recursos VALUES (DEFAULT, 8000, 1);

-- Podem ser utilizados os seguintes programas:
INSERT INTO programas VALUES (DEFAULT, 'Java', 1000);
INSERT INTO programas VALUES (DEFAULT, 'C#', 1000);
INSERT INTO programas VALUES (DEFAULT, 'Renderizador', 6000);

-- Um programa precisa ter uma instancia para ser executado:
INSERT INTO instancias (id_instancia, id_recurso, id_programa) VALUES (DEFAULT, 1, 1);
INSERT INTO instancias (id_instancia, id_recurso, id_programa) VALUES (DEFAULT, 1, 2);
INSERT INTO instancias (id_instancia, id_recurso, id_programa) VALUES (DEFAULT, 1, 3);
INSERT INTO instancias (id_instancia, id_recurso, id_programa) VALUES (DEFAULT, 1, 1);

-- Cada instancia precisa de uma fila contectada
INSERT INTO filas VALUES (DEFAULT, 1);
INSERT INTO filas VALUES (DEFAULT, 2);
INSERT INTO filas VALUES (DEFAULT, 3);

-- Os alunos da instituiÃ§Ã£o foram cadastrados:
INSERT INTO alunos (id_aluno, nome, email, senha) VALUES (DEFAULT, 'user1', 'email@email.com', '123');
INSERT INTO alunos (id_aluno, nome, email, senha) VALUES (DEFAULT, 'user2', 'email1@email.com', '456');
INSERT INTO alunos (id_aluno, nome, email, senha) VALUES (DEFAULT, 'user3', 'email2@email.com', '789');
INSERT INTO alunos (id_aluno, nome, email, senha) VALUES (DEFAULT, 'user4', 'email3@email.com', '012');

-- Ao utilizar as instancias dos programas, os alunos acessam uma fila:
INSERT INTO alunos_fila (id_alunos_fila, id_usuario, id_fila, data_entrada, data_saida, comando) 
                 VALUES (DEFAULT, 1, 1, DEFAULT, NULL, to_clob('System.out.println("Hello World!");'));
INSERT INTO alunos_fila (id_alunos_fila, id_usuario, id_fila, data_entrada, data_saida, comando) 
                 VALUES (DEFAULT, 2, 1, DEFAULT, NULL, to_clob('System.out.println("Hello World!");'));
INSERT INTO alunos_fila (id_alunos_fila, id_usuario, id_fila, data_entrada, data_saida, comando)
                 VALUES (DEFAULT, 3, 3, DEFAULT, NULL, to_clob('Arquivo binario gigante...'));
INSERT INTO alunos_fila (id_alunos_fila, id_usuario, id_fila, data_entrada, data_saida, comando) 
                 VALUES (DEFAULT, 1, 1, DEFAULT, NULL, to_clob('System.out.println("Hell World!");'));
INSERT INTO alunos_fila (id_alunos_fila, id_usuario, id_fila, data_entrada, data_saida, comando)
                 VALUES (DEFAULT, 1, 1, DEFAULT, NULL, to_clob('System.out.println("Hello World!");'));

-- Quando o comando é processado, ele sai da fila e vai para a instancia (deve ser executado em transação):
-- A instancia 1 não está executando nada... O proximo comando é chamado:
UPDATE alunos_fila af SET af.data_saida = sysdate WHERE af.id_alunos_fila = 1;
INSERT INTO aluno_fila_instancia (iniciou_em, id_aluno_fila, id_instancia, terminou_em) VALUES (sysdate, 1, 1, NULL);
-- o comando (referido 1) está executando na instância 1

-- A instancia 3 não está executando nada... O proximo comando é chamado:
UPDATE alunos_fila af SET af.data_saida = sysdate WHERE af.id_alunos_fila = 3;
INSERT INTO aluno_fila_instancia (iniciou_em, id_aluno_fila, id_instancia, terminou_em) VALUES (sysdate, 3, 3, NULL);
-- o comando (referido 2) está executando na instância 3

-- A instancia 1 concluíu a execução do comando
UPDATE aluno_fila_instancia SET terminou_em = sysdate WHERE iniciou_em IN(SELECT iniciou_em FROM (
    SELECT afi.iniciou_em FROM aluno_fila_instancia afi ORDER BY afi.iniciou_em DESC
) WHERE rownum = 1) AND id_instancia = 1;
-- o comando 1 foi retirado da fila e agora possui terminou_em != NULL

-- A instancia 1 não está executando nada... O proximo comando é chamado:
UPDATE alunos_fila af SET af.data_saida = sysdate WHERE af.id_alunos_fila = 2;
INSERT INTO aluno_fila_instancia (iniciou_em, id_aluno_fila, id_instancia, terminou_em) VALUES (sysdate, 2, 1, NULL);
-- o comando (referido 3) está executando na instância 1

-- A instancia 1 concluíu a execução do comando
UPDATE aluno_fila_instancia SET terminou_em = sysdate WHERE iniciou_em IN(SELECT iniciou_em FROM (
    SELECT afi.iniciou_em FROM aluno_fila_instancia afi ORDER BY afi.terminou_em DESC
) WHERE rownum = 1) AND id_instancia = 1;
-- o comando 3 foi retirado da fila e agora possui terminou_em != NULL

-- A instancia 3 concluíu a execução do comando
UPDATE aluno_fila_instancia SET terminou_em = sysdate WHERE iniciou_em IN(SELECT iniciou_em FROM (
    SELECT afi.iniciou_em FROM aluno_fila_instancia afi ORDER BY afi.terminou_em DESC
) WHERE rownum = 1) AND id_instancia = 3;
-- o comando 2 foi retirado da fila e agora possui terminou_em != NULL
