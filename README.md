# Esp8266 e Wake on Lan — Ligando seu PC remotamente

Um simples projeto para exemplificar a utilização de um Esp8266 enviando pacotes mágicos (Wake on Lan) para ligar o PC!

> Artigo original publicado no Medium em 7 de maio de 2022: [Esp8266 e Wake on Lan — Ligando seu PC remotamente](https://paulobtx.medium.com/esp8266-e-wake-on-lan-ligando-seu-pc-remotamente-ed7dbc6f5bdd)

![Wake on Lan](https://miro.medium.com/v2/resize:fit:700/1*0gUgZeVuKFOzJqZRxdZIqg.jpeg)

*Imagem retirada da Wikipédia*

Se você é um dev empolgado como eu e quer achar utilidades para as plaquinhas "Esp" que você comprou, saiba que nesse artigo eu vou te ajudar a ligar o seu computador através da tecnologia **Wake On Lan**.

## Ativando a funcionalidade na BIOS

Sem enrolação e direto ao ponto.

Boa parte das placas de rede mais atuais já contam com essa tecnologia, porém a sua funcionalidade vem desabilitada de fábrica.

Vou deixar alguns prints aqui de como aparece na minha máquina. Pode variar um pouco de placa para placa, mas tente dar uma pesquisada para ver se você chega na mesma opção.

1. Na tela inicial da BIOS, selecione a opção **Advanced Mode**.

![BIOS - Advanced Mode](https://miro.medium.com/v2/resize:fit:700/1*imB59uvrYMwB_5hZYvnH6Q.png)

2. Selecione novamente a aba **Advanced** e procure pela opção **APM Configuration**.

![BIOS - APM Configuration](https://miro.medium.com/v2/resize:fit:700/1*OMx5EMyHCYqo3OQpI8XUtA.png)

3. Marque como **Enabled** a opção **Power On By PCI-E**.

![BIOS - Power On By PCI-E](https://miro.medium.com/v2/resize:fit:700/1*pkjG8RN3fvyfm-fe59Q3Tg.png)

4. Não se esqueça de salvar antes de sair das configurações.

![BIOS - Salvar e sair](https://miro.medium.com/v2/resize:fit:700/1*RhpQ1ZN-5gd1xADIX7_T0w.png)

## Descobrindo o MAC Address

Se você estiver usando o Windows, você pode ir no menu de configurações e selecionar a opção de **Rede e Internet**.

Clique em propriedades da rede que está ativa. A maioria das pessoas utiliza apenas uma placa de rede, mas se o seu caso for diferente, você precisa verificar qual irá funcionar.

Guarde o valor que estiver em **Endereço Físico**. No meu caso eu escondi por questões de segurança.

## Codificando

Você não precisa fazer nenhum "jumpeamento", conexão nem nada em questão de hardware. Apenas anexar o código e alimentar a energia do seu Esp. Vou explicando parte por parte para você entender.

No meu caso eu utilizo o Visual Studio Code com o PlatformIO. Para preparar o seu ambiente, você pode começar por aqui: https://platformio.org/install/ide?install=vscode

Primeiramente, instale essa biblioteca em seu projeto:

![Biblioteca WakeOnLan no PlatformIO](https://miro.medium.com/v2/resize:fit:700/1*6QhC2O3mOtMNakV0BErO4w.png)

Em seguida, utilize o código do arquivo [main.cpp](main.cpp) e envie para o seu ESP! O código está bem explicado. Basicamente você precisa configurar as 3 constantes que contêm o **SSID** (do seu Wi-Fi), a **senha** e aquele **MAC Address** que conseguimos lá atrás.

## Testando

Após tudo pronto e o código já no seu Esp, analise o terminal para descobrir em qual IP ele está rodando.

![Terminal mostrando o IP](https://miro.medium.com/v2/resize:fit:700/1*9Tmbbdoh9hBqHZ1BOCEVGQ.png)

Sabendo disso, desconecte-o do PC, ligue-o em outra fonte de energia e desligue seu PC.

No seu navegador (do celular, por exemplo) acesse o endereço `http://192.168.3.48/wakeMyPC` (troque pelo IP do seu Esp).

![Acessando o endereço no navegador](https://miro.medium.com/v2/resize:fit:700/1*R2seKP-IJvNRSiIJRL-frA.png)

Se o seu PC estiver desligado, nesse momento ele deverá ligar. 🎉

Também é possível enviar esses comandos via Telegram, mas fica para outro artigo.

## Contato

LinkedIn: https://www.linkedin.com/in/paulobtx/
