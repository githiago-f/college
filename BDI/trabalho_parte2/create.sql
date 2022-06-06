CREATE SEQUENCE s_instituicao START WITH 1;

CREATE TABLE instituicoes ( 
    id_instituicao NUMBER DEFAULT s_instituicao.nextval, 
    nome VARCHAR(80), 
    CONSTRAINT pk_client PRIMARY KEY(id_instituicao) 
);

CREATE SEQUENCE s_recurso START WITH 1;

CREATE TABLE recursos ( 
    id_recurso NUMBER DEFAULT s_recurso.nextval, 
    capacidade NUMBER,
    id_instituicao NUMBER, 
    CONSTRAINT pk_recurso PRIMARY KEY(id_recurso) 
);

ALTER TABLE recursos ADD CONSTRAINT fk_id_instituicao_recurso FOREIGN KEY(id_instituicao) REFERENCES instituicoes;

CREATE SEQUENCE s_programas START WITH 1;

CREATE TABLE programas (  
    id_programa NUMBER DEFAULT s_programas.nextval,  
    nome VARCHAR(255)  NOT NULL,
    mem_consumida_apr NUMBER DEFAULT 0,
    CONSTRAINT pk_programas PRIMARY KEY(id_programa)  
);

CREATE SEQUENCE s_instancia START WITH 1;

CREATE TABLE instancias ( 
    id_instancia NUMBER DEFAULT s_instancia.nextval, 
    id_recurso NUMBER, 
    id_programa NUMBER, 
    CONSTRAINT pk_instancias PRIMARY KEY(id_instancia) 
);

ALTER TABLE instancias ADD CONSTRAINT fk_id_recurso_instancia FOREIGN KEY(id_recurso) REFERENCES recursos;
ALTER TABLE instancias ADD CONSTRAINT fk_id_programa_instancia FOREIGN KEY(id_programa) REFERENCES programas;

CREATE SEQUENCE s_fila START WITH 1;

CREATE TABLE filas ( 
    id_fila NUMBER DEFAULT s_fila.nextval, 
    id_instancia NUMBER, 
    CONSTRAINT pk_filas PRIMARY KEY(id_fila) 
);

ALTER TABLE filas ADD CONSTRAINT fk_id_instancia_fila FOREIGN KEY(id_instancia) REFERENCES instancias;

CREATE SEQUENCE s_aluno START WITH 1;

CREATE TABLE alunos (
    id_aluno NUMBER DEFAULT s_aluno.nextval, 
    nome VARCHAR(255),
    email VARCHAR(255),
    senha VARCHAR(64),
    CONSTRAINT pk_alunos PRIMARY KEY(id_aluno),
    CONSTRAINT u_email UNIQUE(email)
);

CREATE SEQUENCE s_alunos_fila START WITH 1;

CREATE TABLE alunos_fila ( 
	id_alunos_fila NUMBER DEFAULT s_alunos_fila.nextval,
    id_usuario NUMBER, 
    id_fila NUMBER, 
    data_entrada DATE DEFAULT sysdate, 
    data_saida DATE,
    comando CLOB,
    CONSTRAINT pk_alunos_fila PRIMARY KEY(id_alunos_fila) 
);

ALTER TABLE alunos_fila ADD CONSTRAINT fk_id_aluno_fila FOREIGN KEY(id_usuario) REFERENCES alunos;
ALTER TABLE alunos_fila ADD CONSTRAINT fk_id_fila_aluno FOREIGN KEY(id_fila) REFERENCES filas;

CREATE TABLE aluno_fila_instancia (
	iniciou_em DATE DEFAULT sysdate,
    id_aluno_fila NUMBER,
    id_instancia NUMBER,
    terminou_em DATE,
    comando CLOB,
    CONSTRAINT pk_aluno_fila_instancia PRIMARY KEY(iniciou_em) 
);

ALTER TABLE aluno_fila_instancia ADD CONSTRAINT fk_id_af_instancia FOREIGN KEY(id_aluno_fila) REFERENCES alunos_fila;
ALTER TABLE aluno_fila_instancia ADD CONSTRAINT fk_id_instancia_aluno FOREIGN KEY(id_instancia) REFERENCES instancias;
