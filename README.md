# Sistema de Gerenciamento de Usuários em C

`ChaveMestre` é um sistema robusto de cadastro e login de usuários e administradores, desenvolvido inteiramente em C. O projeto foi construído com foco em segurança, modularidade e uma interface de terminal limpa e interativa. Ele serve como uma solução completa para gerenciamento de perfis, com funcionalidades distintas para usuários padrão e administradores do sistema.

## 🎯 Objetivo do Projeto

O objetivo principal do `ChaveMestre` é fornecer uma base de código segura e bem estruturada para um sistema de autenticação. Ele foi projetado para demonstrar práticas de programação defensiva em C, manipulação segura de arquivos, interação com APIs externas (para envio de e-mails) e a criação de uma interface de usuário funcional no ambiente de console.

---

## ✨ Funcionalidades

O sistema é dividido em dois módulos principais: um para usuários e outro para administradores.

### **Para Usuários:**
* **Cadastro Seguro:** Criação de novas contas de usuário com validação de dados.
* **Login:** Acesso à conta com verificação de nome e senha.
* **Recuperação de Senha:** Mecanismo de recuperação através de uma pergunta e resposta secreta.
* **Notificações por E-mail:** Recebimento de e-mails para confirmar cadastro, login e alterações de senha.

### **Para Administradores:**
* **Acesso Restrito:** Login seguro para administradores.
* **Gerenciamento de Usuários:**
    * **Listagem Completa:** Visualização de todos os usuários e administradores cadastrados.
    * **Localização de Usuário:** Busca de perfis específicos por nome.
    * **Exclusão de Usuário:** Remoção de contas de usuário do sistema.
* **Notificações por E-mail:** Alertas sobre atividades na conta de administrador.

---

## 🛠️ Detalhes Técnicos

* **Armazenamento de Dados:** As informações são persistidas em arquivos binários (`usuarios_cadastrados.bin` e `adms_cadastrados.bin`), garantindo eficiência na leitura e escrita dos dados.
* **Segurança de Dados:** Senhas e respostas secretas são ofuscadas usando uma **Cifra de César** antes de serem salvas, adicionando uma camada básica de proteção. A entrada de senhas é mascarada na tela.
* **Interface de Terminal (ADK):** O projeto utiliza um kit de desenvolvimento próprio, o **ANSIstyle Dev Kit (ADK)**, para criar uma interface rica no terminal, com bordas, cores e posicionamento de cursor, que funciona tanto em Windows quanto em Linux.
* **Programação Defensiva:** Uma técnica de alocação de buffer inteligente é usada para ler entradas de texto, prevenindo erros comuns de buffer e garantindo que o caractere de nova linha (`\n`) seja tratado corretamente.
* **Envio de E-mails:** A biblioteca **libcurl** é utilizada para se comunicar com o servidor SMTP do Gmail, permitindo o envio de notificações via SMTPS (SMTP seguro sobre SSL).

---

## 🚀 Como Baixar e Usar

Para compilar e executar o projeto em sua máquina (Windows), você precisará do ambiente MSYS2. Siga os passos abaixo.

### **1. Pré-requisitos e Instalação**

Primeiro, instale o MSYS2 e as ferramentas necessárias para a compilação.

1.  **Baixe e instale o MSYS2:**
    * Acesse o site oficial e faça o download: [https://www.msys2.org/](https://www.msys2.org/)

2.  **Abra o terminal MSYS2 MinGW 64-bit.**

3.  **Atualize os pacotes do MSYS2:**
    * Execute o comando abaixo e feche o terminal se for solicitado. Depois, abra-o novamente e execute o segundo comando.
    ```bash
    pacman -Syu
    pacman -Su
    ```

4.  **Instale as ferramentas de compilação e a biblioteca libcurl:**
    * Este comando instalará o compilador `gcc`, a ferramenta `make` e a biblioteca `curl` necessária para o envio de e-mails.
    ```bash
    pacman -S make mingw-w64-x86_64-gcc mingw-w64-x86_64-curl
    ```

### **2. Compilação e Execução**

Após configurar os pré-requisitos, você pode compilar e rodar o projeto.

1.  **Navegue até o diretório do projeto:**
    * Use o comando `cd` no terminal MSYS2. Por exemplo, se seu projeto está na Área de Trabalho:
    ```bash
    cd /c/Users/SeuUsuario/Desktop/ChaveMestre
    ```

2.  **Compile o projeto:**
    * O projeto já contém um `Makefile` que automatiza a compilação. Basta usar o comando:
    ```bash
    make
    ```
    * Isso irá compilar todos os arquivos `.c` e gerar um executável chamado `programa`.

3.  **Execute o programa:**
    * Para iniciar o sistema, execute o arquivo gerado:
    ```bash
    ./programa
    ```

Agora o sistema `ChaveMestre` estará em execução no seu terminal! 🎉
