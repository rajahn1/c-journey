# Projeto: C-PassVault - Gerenciador de Senhas Local em C

**Versão:** 1.0
**Autor:** [Seu Nome/Apelido Aqui]
**Data:** 19 de Abril de 2025

## Visão Geral

C-PassVault é um gerenciador de senhas de linha de comando (CLI) desenvolvido inteiramente em linguagem C. Seu objetivo principal é fornecer uma solução segura e *exclusivamente local* para armazenar e gerenciar credenciais de acesso (nomes de usuário e senhas) para diversos serviços. O projeto não utiliza bancos de dados externos ou conexão com a internet, garantindo que todos os dados sensíveis permaneçam sob o controle direto do usuário, criptografados em um arquivo local.

## Objetivo do Projeto

O projeto visa resolver o problema comum da "fadiga de senhas" e da prática insegura de reutilizar senhas ou anotá-las em locais não seguros. Ao oferecer um cofre digital criptografado e acessível por uma única senha mestra, o C-PassVault permite aos usuários:

1.  **Centralizar:** Armazenar todas as credenciais em um único local seguro.
2.  **Proteger:** Manter as senhas criptografadas em repouso (no arquivo) usando algoritmos robustos.
3.  **Simplificar:** Acessar rapidamente as credenciais necessárias através de uma interface de linha de comando simples.
4.  **Fortalecer:** Gerar senhas fortes e aleatórias para novos serviços.
5.  **Manter a Privacidade:** Garantir que os dados nunca saiam da máquina local do usuário.

Este projeto serve como um excelente exercício prático para aprimorar habilidades em C, especialmente em manipulação de arquivos, estruturas de dados, gerenciamento de memória, criptografia básica e desenvolvimento de aplicações CLI robustas.

## Funcionalidades Principais (Requisitos Funcionais)

* **[RF01] Inicialização do Cofre:** Criar um novo arquivo de cofre (`vault.bin`, por exemplo) caso ele não exista, solicitando a definição de uma senha mestra.
* **[RF02] Autenticação:** Solicitar a senha mestra para desbloquear o cofre antes de permitir qualquer operação de leitura ou escrita.
* **[RF03] Adicionar Credencial:** Permitir ao usuário adicionar uma nova entrada contendo:
    * Nome do Serviço/Site (ex: "Google", "GitHub")
    * Nome de Usuário/Email
    * Senha
* **[RF04] Listar Serviços:** Exibir uma lista de todos os nomes de serviços armazenados no cofre.
* **[RF05] Visualizar Credencial:** Exibir os detalhes (usuário e senha) de um serviço específico, buscando pelo nome do serviço.
* **[RF06] Copiar Senha (Opcional Avançado):** Copiar a senha de um serviço específico para a área de transferência do sistema (requer bibliotecas específicas de plataforma ou abordagens mais complexas). Como alternativa inicial, apenas exibir a senha na tela.
* **[RF07] Remover Credencial:** Permitir a exclusão de uma entrada do cofre, buscando pelo nome do serviço.
* **[RF08] Gerar Senha:** Implementar um gerador de senhas aleatórias com opções configuráveis (comprimento, uso de maiúsculas, minúsculas, números, símbolos).
* **[RF09] Alterar Senha Mestra:** Permitir que o usuário altere a senha mestra do cofre (requer re-criptografia do cofre).
* **[RF10] Pesquisar Serviço:** Buscar entradas por nome de serviço (correspondência exata ou parcial).

## Requisitos Não Funcionais

* **[RNF01] Segurança:**
    * Utilizar criptografia simétrica forte (ex: AES-256) para cifrar o conteúdo do arquivo do cofre.
    * Derivar a chave de criptografia a partir da senha mestra usando uma função de derivação de chave baseada em senha (PBKDF) robusta (ex: PBKDF2) com salt.
    * Armazenar o salt junto com os dados cifrados no arquivo do cofre.
    * Proteger a senha mestra em memória (evitar mantê-la em texto claro por mais tempo que o necessário, limpar buffers).
    * Não armazenar a senha mestra em texto claro em nenhum local.
* **[RNF02] Usabilidade:**
    * Interface de linha de comando clara e intuitiva.
    * Mensagens de erro informativas.
    * Feedback adequado para cada operação realizada.
* **[RNF03] Portabilidade:**
    * O código deve ser escrito em C padrão (C99 ou C11) para maximizar a compatibilidade.
    * Minimizar dependências externas. Se usar bibliotecas (como para criptografia), que sejam comuns e multiplataforma (ex: OpenSSL) ou fornecer instruções claras para instalação.
* **[RNF04] Desempenho:**
    * Operações de criptografia/decriptografia e leitura/escrita de arquivo devem ser eficientes, sem atrasos perceptíveis para cofres de tamanho razoável.
* **[RNF05] Confiabilidade:**
    * Garantir a integridade dos dados. O aplicativo não deve corromper o arquivo do cofre, mesmo em caso de erros (ex: falta de espaço em disco, interrupção abrupta). Usar escritas atômicas ou arquivos temporários pode ajudar.
* **[RNF06] Manutenibilidade:**
    * Código bem estruturado e modularizado (divisão em arquivos `.c` e `.h`).
    * Comentários claros no código.
    * Uso de nomes de variáveis e funções significativos.

## Conceitos Praticados

* **Manipulação de Arquivos:** Leitura e escrita de dados binários (`fopen`, `fread`, `fwrite`, `fclose`, `fseek`). Tratamento de erros de I/O.
* **Estruturas de Dados:** Definição de `structs` para representar as credenciais. Uso de arrays dinâmicos (`malloc`, `realloc`, `free`) ou listas encadeadas para armazenar as entradas em memória.
* **Gerenciamento de Memória:** Alocação e liberação dinâmica de memória. Prevenção de vazamentos de memória (`memory leaks`). Limpeza segura de buffers contendo dados sensíveis (`memset`, `memset_s` se disponível).
* **Manipulação de Strings:** Funções da biblioteca `<string.h>` (`strcpy`, `strncpy`, `strcmp`, `strlen`, etc.). Cuidado com buffer overflows.
* **Criptografia:**
    * **Hashing:** Uso de algoritmos como SHA-256 para verificar a senha mestra (opcionalmente, para derivar a chave).
    * **Key Derivation:** Implementação ou uso de PBKDF2 para derivar uma chave segura a partir da senha mestra e um salt.
    * **Criptografia Simétrica:** Uso de AES (em modo como CBC ou GCM) para cifrar e decifrar o conteúdo do cofre.
    * **Geração de Números Aleatórios Seguros:** Para criar salts e senhas fortes (`/dev/urandom` em Linux/macOS, `CryptGenRandom` no Windows, ou funções de bibliotecas criptográficas).
* **Modularização:** Organização do código em múltiplos arquivos fonte (`.c`) e cabeçalhos (`.h`) para melhor organização e reutilização (ex: `main.c`, `crypto.c`, `storage.c`, `ui.c`, `utils.c`).
* **Parsing de Argumentos de Linha de Comando:** Processar `argc` e `argv` para determinar a ação que o usuário deseja executar (ex: `cpassvault add`, `cpassvault list`).
* **Tratamento de Erros:** Verificação robusta de valores de retorno de funções (I/O, alocação de memória, criptografia) e tratamento adequado de condições de erro.
* **Build Systems (Opcional):** Criação de um `Makefile` para automatizar o processo de compilação e linkagem.

## Tecnologias/Bibliotecas Sugeridas

* **Linguagem:** C (C99 ou C11)
* **Compilador:** GCC ou Clang
* **Biblioteca Padrão C:** `stdio.h`, `stdlib.h`, `string.h`, `time.h` (para seeds simples de RNG, se não usar cripto seguro), etc.
* **Biblioteca de Criptografia:**
    * **OpenSSL (libcrypto):** Padrão de indústria, robusta e multiplataforma, porém pode ser complexa para iniciantes e adiciona uma dependência externa significativa. Oferece AES, SHA-256, PBKDF2, geradores de números aleatórios seguros.
    * **libsodium:** Uma biblioteca moderna e fácil de usar para criptografia, focada em segurança e usabilidade. Boa alternativa ao OpenSSL para muitos casos.
    * *Alternativa Mínima (Não Recomendada para Segurança Real):* Implementar algoritmos mais simples (como RC4 ou XOR simples *apenas para fins didáticos iniciais*, substituindo por AES posteriormente) ou usar bibliotecas "header-only" de AES, se encontradas e bem avaliadas. **Enfatizar que para um portfólio sério, usar bibliotecas testadas como OpenSSL ou libsodium é crucial.**
* **Build System:** Make

## Roadmap de Desenvolvimento (Sprints)

Este roadmap divide o projeto em etapas gerenciáveis, começando do básico e adicionando complexidade gradualmente.

---

### Sprint 0: Configuração e Estrutura Básica (Duração: ~1-2 dias)

* **Objetivo:** Preparar o ambiente de desenvolvimento, definir a estrutura do projeto e a lógica básica de inicialização.
* **Tarefas:**
    1.  [ ] Criar um repositório Git (`git init`).
    2.  [ ] Definir a estrutura de diretórios (ex: `src/`, `include/`, `bin/`, `data/`).
    3.  [ ] Criar um `Makefile` básico para compilar o projeto.
    4.  [ ] Definir a `struct Credential` em um arquivo de cabeçalho (`credential.h`).
    5.  [ ] Criar o arquivo `main.c` com a função `main`.
    6.  [ ] Implementar o parsing básico de argumentos de linha de comando (usando `argc`, `argv`) para identificar ações futuras (ex: "init", "add", "list").
    7.  [ ] Escrever uma função simples para verificar se o arquivo do cofre existe.

---

### Sprint 1: Armazenamento Central (Plaintext) (Duração: ~3-5 dias)

* **Objetivo:** Implementar a capacidade de adicionar, listar e salvar/carregar credenciais em um arquivo *sem criptografia* (para facilitar a depuração inicial).
* **Tarefas:**
    1.  [ ] Implementar a função `add_credential()`: recebe dados da credencial, aloca memória para a `struct Credential`, adiciona a um array dinâmico ou lista encadeada em memória.
    2.  [ ] Implementar a função `list_services()`: itera sobre as credenciais em memória e imprime os nomes dos serviços.
    3.  [ ] Implementar a função `save_vault()`: escreve o array/lista de `struct Credential` para um arquivo binário (ex: `vault.dat`). **Ainda sem criptografia.** Cuidar da serialização (como escrever structs de tamanho variável ou strings).
    4.  [ ] Implementar a função `load_vault()`: lê o arquivo binário e recarrega as credenciais na estrutura de dados em memória.
    5.  [ ] Integrar `save_vault` e `load_vault` no fluxo principal (carregar ao iniciar, salvar ao adicionar/modificar/sair).
    6.  [ ] Implementar o comando `add` (recebe serviço, usuário, senha via CLI ou prompt interativo).
    7.  [ ] Implementar o comando `list`.

---

### Sprint 2: Senha Mestra e Criptografia Básica (Duração: ~5-7 dias)

* **Objetivo:** Introduzir a senha mestra e criptografar o arquivo do cofre.
* **Tarefas:**
    1.  [ ] **Escolher e Configurar Biblioteca Criptográfica:** Decidir entre OpenSSL, libsodium ou outra. Instalar e configurar o `Makefile` para linkar com a biblioteca escolhida.
    2.  [ ] Criar módulo `crypto.c`/`crypto.h`.
    3.  [ ] Implementar função para ler a senha mestra do usuário de forma segura (desativando o eco no terminal, se possível - requer bibliotecas específicas ou condicionais de compilação).
    4.  [ ] Implementar função para gerar um salt aleatório seguro.
    5.  [ ] Implementar função para derivar a chave de criptografia usando PBKDF2 (da biblioteca escolhida) a partir da senha mestra e do salt.
    6.  [ ] Modificar `save_vault()`:
        * Serializar os dados das credenciais para um buffer em memória.
        * Gerar um novo salt (ou usar um fixo inicialmente para testes).
        * Derivar a chave de criptografia.
        * Criptografar o buffer usando AES (ex: AES-256-CBC) com a chave derivada e um IV (Vetor de Inicialização) aleatório.
        * Escrever o salt, o IV e os dados cifrados no arquivo do cofre.
    7.  [ ] Modificar `load_vault()`:
        * Ler o salt e o IV do arquivo.
        * Solicitar a senha mestra.
        * Derivar a chave de criptografia usando a senha fornecida e o salt lido.
        * Decriptografar os dados usando AES com a chave derivada e o IV lido.
        * *Verificação:* Incluir um bloco de verificação (ex: um hash conhecido ou um "magic number") no início dos dados plaintext para verificar se a decriptografia foi bem-sucedida (senha mestra correta). Retornar erro se a verificação falhar.
        * Desserializar o buffer decriptografado de volta para a estrutura de dados em memória.
    8.  [ ] Implementar o fluxo de inicialização (`init`): solicitar senha mestra, gerar salt, criar um cofre vazio criptografado (talvez com o bloco de verificação).
    9.  [ ] Adicionar o requisito de senha mestra antes dos comandos `add` e `list`.

---

### Sprint 3: Operações CRUD Completas (Duração: ~4-6 dias)

* **Objetivo:** Implementar as funcionalidades restantes de visualização, remoção e pesquisa.
* **Tarefas:**
    1.  [ ] Implementar a função `find_credential_by_service()`: busca uma credencial pelo nome do serviço no array/lista em memória.
    2.  [ ] Implementar o comando `get <service_name>`: usa `find_credential_by_service`, e se encontrar, exibe o nome de usuário e a senha. **Importante:** Limpar a senha da memória/tela após o uso, se possível.
    3.  [ ] Implementar o comando `delete <service_name>`: usa `find_credential_by_service`, remove a credencial encontrada da estrutura em memória e chama `save_vault()` para persistir a mudança. Adicionar confirmação ("Tem certeza?").
    4.  [ ] Implementar o comando `search <search_term>`: busca serviços cujos nomes contenham o termo de busca (correspondência parcial).
    5.  [ ] Implementar o comando `change-master-password`:
        * Solicita a senha mestra atual.
        * Verifica a senha atual (tentando decriptografar o cofre).
        * Solicita a nova senha mestra (duas vezes, para confirmação).
        * Gera um novo salt.
        * Deriva a nova chave de criptografia.
        * Re-criptografa o conteúdo do cofre (que já está em memória) com a nova chave, salt e IV.
        * Salva o cofre atualizado no arquivo.

---

### Sprint 4: Geração de Senhas e Melhorias de Segurança (Duração: ~3-5 dias)

* **Objetivo:** Adicionar a funcionalidade de geração de senhas e refinar a segurança geral.
* **Tarefas:**
    1.  [ ] Implementar a função `generate_password()` em `utils.c`/`utils.h`:
        * Recebe parâmetros: comprimento, incluir maiúsculas, minúsculas, números, símbolos.
        * Usa um gerador de números aleatórios *criptograficamente seguro* (da biblioteca de cripto ou do sistema operacional) para selecionar caracteres aleatórios do conjunto permitido.
        * Retorna a senha gerada.
    2.  [ ] Implementar o comando `generate [options]`: chama `generate_password()` e exibe a senha gerada.
    3.  [ ] **Revisão de Segurança:**
        * Verificar se todos os buffers que contêm senhas (mestra ou de credenciais) são limpos da memória (`memset`) o mais rápido possível após o uso. Considerar `memset_s` se disponível.
        * Garantir que salts e IVs são gerados aleatoriamente para cada criptografia (exceto o salt da senha mestra, que é fixo por cofre).
        * Validar todas as entradas do usuário para evitar overflows ou comportamentos inesperados.
        * Revisar o tratamento de erros em operações de criptografia e I/O.
    4.  [ ] (Opcional) Implementar bloqueio do cofre após um tempo de inatividade ou número de tentativas de senha mestra erradas.

---

### Sprint 5: Refinamento, Testes e Documentação (Duração: ~4-6 dias)

* **Objetivo:** Polir a aplicação, realizar testes extensivos e finalizar a documentação.
* **Tarefas:**
    1.  [ ] Melhorar a interface do usuário (CLI): formatar a saída, adicionar mensagens de ajuda (`--help` ou comando `help`).
    2.  [ ] Realizar testes manuais abrangentes:
        * Casos de uso normais (adicionar, listar, obter, deletar, gerar, mudar senha mestra).
        * Casos de erro (senha mestra errada, arquivo não encontrado, arquivo corrompido, serviço não encontrado, entrada inválida).
        * Casos limite (cofre vazio, muitos registros, nomes de serviço/senhas longos ou com caracteres especiais).
    3.  [ ] (Opcional Avançado) Escrever testes unitários para funções críticas (criptografia, manipulação de dados), se familiarizado com frameworks de teste C (ex: Check, CUnit).
    4.  [ ] Revisar e refatorar o código: melhorar clareza, remover código morto, otimizar se necessário.
    5.  [ ] Adicionar comentários explicativos no código onde for necessário.
    6.  [ ] **Finalizar este `README.md`:** Incluir instruções claras de compilação e execução, dependências, exemplos de uso.
    7.  [ ] Criar um arquivo `LICENSE` (ex: MIT, GPLv3).
    8.  [ ] Limpar o repositório Git, criar tags de versão.

## Como Compilar e Executar (Exemplo)

*(Esta seção deve ser preenchida com os comandos reais após a implementação)*

**Dependências:**

* Compilador C (GCC ou Clang)
* Make
* Biblioteca OpenSSL (desenvolvimento - ex: `libssl-dev` no Debian/Ubuntu, `openssl-devel` no Fedora) ou Libsodium.

**Compilação:**

```bash
make
# Inicializar o cofre (primeira vez)
./bin/cpassvault init

# Adicionar uma nova credencial
./bin/cpassvault add

# Listar todos os serviços
./bin/cpassvault list

# Obter detalhes de um serviço
./bin/cpassvault get "Nome Do Servico"

# Gerar uma senha de 16 caracteres com símbolos
./bin/cpassvault generate -l 16 -s

# Ver ajuda
./bin/cpassvault --help

Okay, aqui está a proposta detalhada para o projeto do Gerenciador de Senhas Local em C, formatada como um README.md.

Markdown

# Projeto: C-PassVault - Gerenciador de Senhas Local em C

**Versão:** 1.0
**Autor:** [Seu Nome/Apelido Aqui]
**Data:** 19 de Abril de 2025

## Visão Geral

C-PassVault é um gerenciador de senhas de linha de comando (CLI) desenvolvido inteiramente em linguagem C. Seu objetivo principal é fornecer uma solução segura e *exclusivamente local* para armazenar e gerenciar credenciais de acesso (nomes de usuário e senhas) para diversos serviços. O projeto não utiliza bancos de dados externos ou conexão com a internet, garantindo que todos os dados sensíveis permaneçam sob o controle direto do usuário, criptografados em um arquivo local.

## Objetivo do Projeto

O projeto visa resolver o problema comum da "fadiga de senhas" e da prática insegura de reutilizar senhas ou anotá-las em locais não seguros. Ao oferecer um cofre digital criptografado e acessível por uma única senha mestra, o C-PassVault permite aos usuários:

1.  **Centralizar:** Armazenar todas as credenciais em um único local seguro.
2.  **Proteger:** Manter as senhas criptografadas em repouso (no arquivo) usando algoritmos robustos.
3.  **Simplificar:** Acessar rapidamente as credenciais necessárias através de uma interface de linha de comando simples.
4.  **Fortalecer:** Gerar senhas fortes e aleatórias para novos serviços.
5.  **Manter a Privacidade:** Garantir que os dados nunca saiam da máquina local do usuário.

Este projeto serve como um excelente exercício prático para aprimorar habilidades em C, especialmente em manipulação de arquivos, estruturas de dados, gerenciamento de memória, criptografia básica e desenvolvimento de aplicações CLI robustas.

## Funcionalidades Principais (Requisitos Funcionais)

* **[RF01] Inicialização do Cofre:** Criar um novo arquivo de cofre (`vault.bin`, por exemplo) caso ele não exista, solicitando a definição de uma senha mestra.
* **[RF02] Autenticação:** Solicitar a senha mestra para desbloquear o cofre antes de permitir qualquer operação de leitura ou escrita.
* **[RF03] Adicionar Credencial:** Permitir ao usuário adicionar uma nova entrada contendo:
    * Nome do Serviço/Site (ex: "Google", "GitHub")
    * Nome de Usuário/Email
    * Senha
* **[RF04] Listar Serviços:** Exibir uma lista de todos os nomes de serviços armazenados no cofre.
* **[RF05] Visualizar Credencial:** Exibir os detalhes (usuário e senha) de um serviço específico, buscando pelo nome do serviço.
* **[RF06] Copiar Senha (Opcional Avançado):** Copiar a senha de um serviço específico para a área de transferência do sistema (requer bibliotecas específicas de plataforma ou abordagens mais complexas). Como alternativa inicial, apenas exibir a senha na tela.
* **[RF07] Remover Credencial:** Permitir a exclusão de uma entrada do cofre, buscando pelo nome do serviço.
* **[RF08] Gerar Senha:** Implementar um gerador de senhas aleatórias com opções configuráveis (comprimento, uso de maiúsculas, minúsculas, números, símbolos).
* **[RF09] Alterar Senha Mestra:** Permitir que o usuário altere a senha mestra do cofre (requer re-criptografia do cofre).
* **[RF10] Pesquisar Serviço:** Buscar entradas por nome de serviço (correspondência exata ou parcial).

## Requisitos Não Funcionais

* **[RNF01] Segurança:**
    * Utilizar criptografia simétrica forte (ex: AES-256) para cifrar o conteúdo do arquivo do cofre.
    * Derivar a chave de criptografia a partir da senha mestra usando uma função de derivação de chave baseada em senha (PBKDF) robusta (ex: PBKDF2) com salt.
    * Armazenar o salt junto com os dados cifrados no arquivo do cofre.
    * Proteger a senha mestra em memória (evitar mantê-la em texto claro por mais tempo que o necessário, limpar buffers).
    * Não armazenar a senha mestra em texto claro em nenhum local.
* **[RNF02] Usabilidade:**
    * Interface de linha de comando clara e intuitiva.
    * Mensagens de erro informativas.
    * Feedback adequado para cada operação realizada.
* **[RNF03] Portabilidade:**
    * O código deve ser escrito em C padrão (C99 ou C11) para maximizar a compatibilidade.
    * Minimizar dependências externas. Se usar bibliotecas (como para criptografia), que sejam comuns e multiplataforma (ex: OpenSSL) ou fornecer instruções claras para instalação.
* **[RNF04] Desempenho:**
    * Operações de criptografia/decriptografia e leitura/escrita de arquivo devem ser eficientes, sem atrasos perceptíveis para cofres de tamanho razoável.
* **[RNF05] Confiabilidade:**
    * Garantir a integridade dos dados. O aplicativo não deve corromper o arquivo do cofre, mesmo em caso de erros (ex: falta de espaço em disco, interrupção abrupta). Usar escritas atômicas ou arquivos temporários pode ajudar.
* **[RNF06] Manutenibilidade:**
    * Código bem estruturado e modularizado (divisão em arquivos `.c` e `.h`).
    * Comentários claros no código.
    * Uso de nomes de variáveis e funções significativos.

## Conceitos Praticados

* **Manipulação de Arquivos:** Leitura e escrita de dados binários (`fopen`, `fread`, `fwrite`, `fclose`, `fseek`). Tratamento de erros de I/O.
* **Estruturas de Dados:** Definição de `structs` para representar as credenciais. Uso de arrays dinâmicos (`malloc`, `realloc`, `free`) ou listas encadeadas para armazenar as entradas em memória.
* **Gerenciamento de Memória:** Alocação e liberação dinâmica de memória. Prevenção de vazamentos de memória (`memory leaks`). Limpeza segura de buffers contendo dados sensíveis (`memset`, `memset_s` se disponível).
* **Manipulação de Strings:** Funções da biblioteca `<string.h>` (`strcpy`, `strncpy`, `strcmp`, `strlen`, etc.). Cuidado com buffer overflows.
* **Criptografia:**
    * **Hashing:** Uso de algoritmos como SHA-256 para verificar a senha mestra (opcionalmente, para derivar a chave).
    * **Key Derivation:** Implementação ou uso de PBKDF2 para derivar uma chave segura a partir da senha mestra e um salt.
    * **Criptografia Simétrica:** Uso de AES (em modo como CBC ou GCM) para cifrar e decifrar o conteúdo do cofre.
    * **Geração de Números Aleatórios Seguros:** Para criar salts e senhas fortes (`/dev/urandom` em Linux/macOS, `CryptGenRandom` no Windows, ou funções de bibliotecas criptográficas).
* **Modularização:** Organização do código em múltiplos arquivos fonte (`.c`) e cabeçalhos (`.h`) para melhor organização e reutilização (ex: `main.c`, `crypto.c`, `storage.c`, `ui.c`, `utils.c`).
* **Parsing de Argumentos de Linha de Comando:** Processar `argc` e `argv` para determinar a ação que o usuário deseja executar (ex: `cpassvault add`, `cpassvault list`).
* **Tratamento de Erros:** Verificação robusta de valores de retorno de funções (I/O, alocação de memória, criptografia) e tratamento adequado de condições de erro.
* **Build Systems (Opcional):** Criação de um `Makefile` para automatizar o processo de compilação e linkagem.

## Tecnologias/Bibliotecas Sugeridas

* **Linguagem:** C (C99 ou C11)
* **Compilador:** GCC ou Clang
* **Biblioteca Padrão C:** `stdio.h`, `stdlib.h`, `string.h`, `time.h` (para seeds simples de RNG, se não usar cripto seguro), etc.
* **Biblioteca de Criptografia:**
    * **OpenSSL (libcrypto):** Padrão de indústria, robusta e multiplataforma, porém pode ser complexa para iniciantes e adiciona uma dependência externa significativa. Oferece AES, SHA-256, PBKDF2, geradores de números aleatórios seguros.
    * **libsodium:** Uma biblioteca moderna e fácil de usar para criptografia, focada em segurança e usabilidade. Boa alternativa ao OpenSSL para muitos casos.
    * *Alternativa Mínima (Não Recomendada para Segurança Real):* Implementar algoritmos mais simples (como RC4 ou XOR simples *apenas para fins didáticos iniciais*, substituindo por AES posteriormente) ou usar bibliotecas "header-only" de AES, se encontradas e bem avaliadas. **Enfatizar que para um portfólio sério, usar bibliotecas testadas como OpenSSL ou libsodium é crucial.**
* **Build System:** Make

## Roadmap de Desenvolvimento (Sprints)

Este roadmap divide o projeto em etapas gerenciáveis, começando do básico e adicionando complexidade gradualmente.

---

### Sprint 0: Configuração e Estrutura Básica (Duração: ~1-2 dias)

* **Objetivo:** Preparar o ambiente de desenvolvimento, definir a estrutura do projeto e a lógica básica de inicialização.
* **Tarefas:**
    1.  [ ] Criar um repositório Git (`git init`).
    2.  [ ] Definir a estrutura de diretórios (ex: `src/`, `include/`, `bin/`, `data/`).
    3.  [ ] Criar um `Makefile` básico para compilar o projeto.
    4.  [ ] Definir a `struct Credential` em um arquivo de cabeçalho (`credential.h`).
    5.  [ ] Criar o arquivo `main.c` com a função `main`.
    6.  [ ] Implementar o parsing básico de argumentos de linha de comando (usando `argc`, `argv`) para identificar ações futuras (ex: "init", "add", "list").
    7.  [ ] Escrever uma função simples para verificar se o arquivo do cofre existe.

---

### Sprint 1: Armazenamento Central (Plaintext) (Duração: ~3-5 dias)

* **Objetivo:** Implementar a capacidade de adicionar, listar e salvar/carregar credenciais em um arquivo *sem criptografia* (para facilitar a depuração inicial).
* **Tarefas:**
    1.  [ ] Implementar a função `add_credential()`: recebe dados da credencial, aloca memória para a `struct Credential`, adiciona a um array dinâmico ou lista encadeada em memória.
    2.  [ ] Implementar a função `list_services()`: itera sobre as credenciais em memória e imprime os nomes dos serviços.
    3.  [ ] Implementar a função `save_vault()`: escreve o array/lista de `struct Credential` para um arquivo binário (ex: `vault.dat`). **Ainda sem criptografia.** Cuidar da serialização (como escrever structs de tamanho variável ou strings).
    4.  [ ] Implementar a função `load_vault()`: lê o arquivo binário e recarrega as credenciais na estrutura de dados em memória.
    5.  [ ] Integrar `save_vault` e `load_vault` no fluxo principal (carregar ao iniciar, salvar ao adicionar/modificar/sair).
    6.  [ ] Implementar o comando `add` (recebe serviço, usuário, senha via CLI ou prompt interativo).
    7.  [ ] Implementar o comando `list`.

---

### Sprint 2: Senha Mestra e Criptografia Básica (Duração: ~5-7 dias)

* **Objetivo:** Introduzir a senha mestra e criptografar o arquivo do cofre.
* **Tarefas:**
    1.  [ ] **Escolher e Configurar Biblioteca Criptográfica:** Decidir entre OpenSSL, libsodium ou outra. Instalar e configurar o `Makefile` para linkar com a biblioteca escolhida.
    2.  [ ] Criar módulo `crypto.c`/`crypto.h`.
    3.  [ ] Implementar função para ler a senha mestra do usuário de forma segura (desativando o eco no terminal, se possível - requer bibliotecas específicas ou condicionais de compilação).
    4.  [ ] Implementar função para gerar um salt aleatório seguro.
    5.  [ ] Implementar função para derivar a chave de criptografia usando PBKDF2 (da biblioteca escolhida) a partir da senha mestra e do salt.
    6.  [ ] Modificar `save_vault()`:
        * Serializar os dados das credenciais para um buffer em memória.
        * Gerar um novo salt (ou usar um fixo inicialmente para testes).
        * Derivar a chave de criptografia.
        * Criptografar o buffer usando AES (ex: AES-256-CBC) com a chave derivada e um IV (Vetor de Inicialização) aleatório.
        * Escrever o salt, o IV e os dados cifrados no arquivo do cofre.
    7.  [ ] Modificar `load_vault()`:
        * Ler o salt e o IV do arquivo.
        * Solicitar a senha mestra.
        * Derivar a chave de criptografia usando a senha fornecida e o salt lido.
        * Decriptografar os dados usando AES com a chave derivada e o IV lido.
        * *Verificação:* Incluir um bloco de verificação (ex: um hash conhecido ou um "magic number") no início dos dados plaintext para verificar se a decriptografia foi bem-sucedida (senha mestra correta). Retornar erro se a verificação falhar.
        * Desserializar o buffer decriptografado de volta para a estrutura de dados em memória.
    8.  [ ] Implementar o fluxo de inicialização (`init`): solicitar senha mestra, gerar salt, criar um cofre vazio criptografado (talvez com o bloco de verificação).
    9.  [ ] Adicionar o requisito de senha mestra antes dos comandos `add` e `list`.

---

### Sprint 3: Operações CRUD Completas (Duração: ~4-6 dias)

* **Objetivo:** Implementar as funcionalidades restantes de visualização, remoção e pesquisa.
* **Tarefas:**
    1.  [ ] Implementar a função `find_credential_by_service()`: busca uma credencial pelo nome do serviço no array/lista em memória.
    2.  [ ] Implementar o comando `get <service_name>`: usa `find_credential_by_service`, e se encontrar, exibe o nome de usuário e a senha. **Importante:** Limpar a senha da memória/tela após o uso, se possível.
    3.  [ ] Implementar o comando `delete <service_name>`: usa `find_credential_by_service`, remove a credencial encontrada da estrutura em memória e chama `save_vault()` para persistir a mudança. Adicionar confirmação ("Tem certeza?").
    4.  [ ] Implementar o comando `search <search_term>`: busca serviços cujos nomes contenham o termo de busca (correspondência parcial).
    5.  [ ] Implementar o comando `change-master-password`:
        * Solicita a senha mestra atual.
        * Verifica a senha atual (tentando decriptografar o cofre).
        * Solicita a nova senha mestra (duas vezes, para confirmação).
        * Gera um novo salt.
        * Deriva a nova chave de criptografia.
        * Re-criptografa o conteúdo do cofre (que já está em memória) com a nova chave, salt e IV.
        * Salva o cofre atualizado no arquivo.

---

### Sprint 4: Geração de Senhas e Melhorias de Segurança (Duração: ~3-5 dias)

* **Objetivo:** Adicionar a funcionalidade de geração de senhas e refinar a segurança geral.
* **Tarefas:**
    1.  [ ] Implementar a função `generate_password()` em `utils.c`/`utils.h`:
        * Recebe parâmetros: comprimento, incluir maiúsculas, minúsculas, números, símbolos.
        * Usa um gerador de números aleatórios *criptograficamente seguro* (da biblioteca de cripto ou do sistema operacional) para selecionar caracteres aleatórios do conjunto permitido.
        * Retorna a senha gerada.
    2.  [ ] Implementar o comando `generate [options]`: chama `generate_password()` e exibe a senha gerada.
    3.  [ ] **Revisão de Segurança:**
        * Verificar se todos os buffers que contêm senhas (mestra ou de credenciais) são limpos da memória (`memset`) o mais rápido possível após o uso. Considerar `memset_s` se disponível.
        * Garantir que salts e IVs são gerados aleatoriamente para cada criptografia (exceto o salt da senha mestra, que é fixo por cofre).
        * Validar todas as entradas do usuário para evitar overflows ou comportamentos inesperados.
        * Revisar o tratamento de erros em operações de criptografia e I/O.
    4.  [ ] (Opcional) Implementar bloqueio do cofre após um tempo de inatividade ou número de tentativas de senha mestra erradas.

---

### Sprint 5: Refinamento, Testes e Documentação (Duração: ~4-6 dias)

* **Objetivo:** Polir a aplicação, realizar testes extensivos e finalizar a documentação.
* **Tarefas:**
    1.  [ ] Melhorar a interface do usuário (CLI): formatar a saída, adicionar mensagens de ajuda (`--help` ou comando `help`).
    2.  [ ] Realizar testes manuais abrangentes:
        * Casos de uso normais (adicionar, listar, obter, deletar, gerar, mudar senha mestra).
        * Casos de erro (senha mestra errada, arquivo não encontrado, arquivo corrompido, serviço não encontrado, entrada inválida).
        * Casos limite (cofre vazio, muitos registros, nomes de serviço/senhas longos ou com caracteres especiais).
    3.  [ ] (Opcional Avançado) Escrever testes unitários para funções críticas (criptografia, manipulação de dados), se familiarizado com frameworks de teste C (ex: Check, CUnit).
    4.  [ ] Revisar e refatorar o código: melhorar clareza, remover código morto, otimizar se necessário.
    5.  [ ] Adicionar comentários explicativos no código onde for necessário.
    6.  [ ] **Finalizar este `README.md`:** Incluir instruções claras de compilação e execução, dependências, exemplos de uso.
    7.  [ ] Criar um arquivo `LICENSE` (ex: MIT, GPLv3).
    8.  [ ] Limpar o repositório Git, criar tags de versão.

## Como Compilar e Executar (Exemplo)

*(Esta seção deve ser preenchida com os comandos reais após a implementação)*

**Dependências:**

* Compilador C (GCC ou Clang)
* Make
* Biblioteca OpenSSL (desenvolvimento - ex: `libssl-dev` no Debian/Ubuntu, `openssl-devel` no Fedora) ou Libsodium.

**Compilação:**

```bash
make
Execução:

Bash

# Inicializar o cofre (primeira vez)
./bin/cpassvault init

# Adicionar uma nova credencial
./bin/cpassvault add

# Listar todos os serviços
./bin/cpassvault list

# Obter detalhes de um serviço
./bin/cpassvault get "Nome Do Servico"

# Gerar uma senha de 16 caracteres com símbolos
./bin/cpassvault generate -l 16 -s

# Ver ajuda
./bin/cpassvault --help
Próximos Passos / Melhorias Futuras (Opcional)
Implementar cópia para a área de transferência de forma segura e multiplataforma.
Adicionar campos extras às credenciais (ex: URL, notas).
Permitir edição de credenciais existentes.
Implementar backup/restauração do arquivo do cofre.
Adicionar suporte a múltiplos cofres.
Criar uma interface gráfica (GUI) usando uma biblioteca como GTK ou Qt (seria um projeto separado, mas poderia usar o backend C).
Melhorar a robustez contra corrupção de arquivos (ex: usar escrita em arquivo temporário e renomear atomicamente).