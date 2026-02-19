# 🪁 Projeto Kite
**Segurança, Sustentabilidade e Inteligência Integrada através de Retrofit.**

Projeto desenvolvido pela **AnGa RetroTechfit** para a disciplina de **Project-based Maker Lab** (4º Ano - Engenharia de Software | FIAP).

👨‍💻 **Autores:** Anna Heloisa Soto Yagyu e Gabriel Pacheco  

---

## 🚨 O Problema
O mercado atual de *Smart Homes* enfrenta três grandes barreiras:
1. **O Custo da Modernização:** Eletrodomésticos com conectividade nativa (IoT) possuem preços proibitivos para a maioria dos brasileiros.
2. **Desperdício Invisível:** O consumo fantasma de aparelhos em *standby* e vazamentos silenciosos de água geram um impacto financeiro e ecológico constante.
3. **Reação vs. Prevenção:** A maioria das soluções avulsas no mercado exige automações manuais e complexas. Quando ocorre um vazamento de gás ou um cano estourado, o dano patrimonial já foi causado antes que o morador perceba.

## 💡 A Solução: Ecossistema Kite
O **Kite** é um kit de **Retrofit Residencial**. Nossa proposta é transformar eletrodomésticos e infraestruturas analógicas em dispositivos inteligentes de forma acessível (plug-and-play), sem necessidade de reformas. 

O diferencial do ecossistema é a **Automação Cruzada Proativa**. Os sensores do kit conversam entre si para garantir segurança ativa. Se o sensor de gás detecta um vazamento, o sistema corta imediatamente a energia de tomadas não essenciais para evitar faíscas e notifica o usuário, atuando como uma apólice de seguro inteligente.

## 🚀 Proposta de Valor e Modelo de Negócios
Nosso projeto se sustenta em três pilares analíticos e de mercado:
* **Segurança (Proteção de Patrimônio):** Evita perdas severas com inundações ou princípios de incêndio.
* **Sustentabilidade (ESG):** Reduz o desperdício hídrico e a pegada de carbono do consumo fantasma.
* **Modelo de Negócios:** * **B2C/B2B2C:** Venda direta dos kits de hardware e parcerias com Seguradoras (desconto na apólice residencial para quem possui o kit instalado).
  * **SaaS Analytics:** Um aplicativo com controle básico gratuito e um *Dashboard Premium* focado em análise de dados, cruzando horários de pico e hábitos de consumo para entregar *insights* reais de economia.

## 🏗️ Arquitetura do Projeto (A Linha Sense)
Para o protótipo (MVP), focaremos na automação de um ambiente crítico, utilizando a nossa linha de sensores integrados ( Linha Sense) :

1. **💧 HydroSense (Água):** Monitoramento contínuo com Sensor de Fluxo. Detecta desde gotejamentos leves até torneiras esquecidas abertas, acionando o corte via Servo Motor.
2. **🔥 AeroSense (Gás/Fumaça):** Sensor MQ-2 integrado à lógica de alerta e corte de energia preventivo.
3. **⚡ EnergySense (Energia):** Smart Plugs com controle via Relé e medição de corrente (ACS712), permitindo ligar/desligar eletrodomésticos e tagueá-los no app como "Essencial" ou "Não Essencial".
4. **🚪 CoreSense (Hub/Painel):** A interface física principal, localizada na saída da residência, permitindo o acionamento rápido de perfis de segurança:
   * **Modo Casa:** Funcionamento padrão. Libera gás e água, mantendo o monitoramento de vazamentos em segundo plano.
   * **Modo Ausente:** Ativado ao sair de casa. Corta o gás preventivamente e desliga todas as tomadas cadastradas no app como "Não Essenciais" (ex: TVs, chaleiras), mantendo apenas as de infraestrutura (geladeira, roteador).
   * **Modo Férias:** Desliga a água geral da casa, bloqueia o gás e envia relatórios semanais detalhados sobre o consumo de energia da residência vazia.

## ⚙️ Tecnologias Utilizadas
* **Microcontrolador:** ESP32 (Wi-Fi/Bluetooth nativo)
* **Linguagem:** C++ (Arduino IDE / Wokwi)
* **Sensores & Atuadores:** YF-S201 (Fluxo de Água), MQ-2 (Gás), ACS712 (Corrente), Módulo Relé, Micro Servo Motor, Display OLED SSD1306.
* **Conectividade & Dados:** Plataforma IoT para comunicação em tempo real e alimentação do Dashboard de Analytics.

## 🔗 Links e Documentação
* **Simulação Virtual:** 
* **Esquemático / Diagrama de Blocos:** 
