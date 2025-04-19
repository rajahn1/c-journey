🔐 Gerenciador de Senhas Local (Password Manager)
Um gerenciador de senhas simples feito em C, com interface via terminal. As senhas são armazenadas localmente em arquivo criptografado, protegidas por uma senha mestre definida pelo usuário.

Este projeto é ideal para praticar conceitos como: criptografia, modularização, estrutura de dados, leitura e escrita de arquivos e segurança em software.

🧭 Roadmap por Sprints (com Tasks)
🏁 Sprint 1: Setup Inicial & Estrutura do Projeto
Foco: Iniciar o projeto, montar a estrutura básica e simular um fluxo inicial.

✅ Tasks:
 Criar repositório e README

 Criar estrutura de pastas:

bash
Copiar
Editar
/src
/include
/data
main.c
 Criar arquivos iniciais:

main.c

password_manager.c / password_manager.h

 Criar menu interativo no terminal com opções:

Login

Cadastrar nova senha

Buscar senha

Sair

 Criar prompt de entrada da senha mestre

 Validar se arquivo data/vault.dat existe

Se não existir, criar um novo arquivo criptografado com base na senha mestre

 Criar função de hash da senha mestre (usar SHA-256)

🔐 Sprint 2: Armazenamento Seguro & Criptografia
Foco: Garantir a segurança dos dados com criptografia.

✅ Tasks:
 Escolher uma biblioteca de criptografia (ex: OpenSSL)

 Criar função encrypt() para criptografar o conteúdo das senhas

 Criar função decrypt() para descriptografar conteúdo

 Definir estrutura de dados:

c
Copiar
Editar
typedef struct {
  char service[50];
  char username[50];
  char password[50]; // armazenada criptografada
} Credential;
 Criar função para armazenar credenciais em arquivo binário criptografado

 Criar função para carregar todas as credenciais descriptografadas

🧪 Sprint 3: CRUD de Senhas
Foco: Permitir manipulação básica de senhas no terminal.

✅ Tasks:
 Criar função para adicionar nova credencial

 Criar função para listar todas as credenciais

 Criar função para buscar credencial por nome do serviço

 Criar função para excluir uma credencial

 Permitir atualização de senha de um serviço

 Validar duplicidade de serviços

🧠 Sprint 4: Geração de Senhas & Qualidade de Vida
Foco: Melhorar a usabilidade do programa com recursos extras.

✅ Tasks:
 Adicionar opção de gerar senha segura automaticamente (com letras, números e símbolos)

 Permitir copiar a senha gerada para a área de transferência (usando lib externa como xclip, pbcopy, etc)

 Criar feedback visual no terminal (cores para mensagens de sucesso/erro)

 Adicionar opção para exibir/esconder senha ao buscar

🗃️ Sprint 5: Persistência & Segurança Avançada
Foco: Proteger ainda mais os dados e melhorar a persistência.

✅ Tasks:
 Criptografar o arquivo inteiro (vault.dat) ao invés de campo por campo

 Salvar o hash da senha mestre na primeira linha do arquivo e verificar antes de descriptografar

 Criar backup automático antes de cada modificação

 Adicionar tentativas de login com limite (bloqueio após 5 tentativas)

🚀 Como rodar o projeto
bash
Copiar
Editar
gcc main.c src/password_manager.c -o password-manager -lssl -lcrypto
./password-manager
Obs: Pode ser necessário instalar o OpenSSL com: sudo apt install libssl-dev

🧩 Possíveis melhorias futuras
Interface gráfica com GTK

Exportação para CSV (criptografado)

Sincronização com nuvem

Suporte a múltiplos cofres (multi-usuário)

Suporte a autenticação com token (2FA)