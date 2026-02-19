# 🪁 Projeto Kite: Ecossistema de Retrofit Inteligente

> **Segurança, Sustentabilidade e Inteligência Integrada através de Retrofit.**
> Projeto desenvolvido pela **AnGa RetroTechfit** para a disciplina de *Project-based Maker Lab* (4º Ano - Engenharia de Software | FIAP).

👨‍💻 **Autores:** Anna Heloisa Soto Yagyu e Gabriel Pacheco

---

## 🚨 O Problema
O mercado atual de *Smart Homes* enfrenta três grandes barreiras:
1. **O Custo da Modernização:** Eletrodomésticos com conectividade nativa (IoT) possuem preços proibitivos.
2. **Desperdício Invisível:** O "consumo fantasma" em *standby* e vazamentos silenciosos de água geram impacto financeiro e ecológico constante.
3. **Reação vs. Prevenção:** A maioria das soluções avulsas apenas avisa o problema. Quando ocorre um vazamento de gás ou inundação, o dano patrimonial já foi causado.

## 💡 A Solução: Ecossistema Kite
O Kite é um kit de **Retrofit Residencial**. Transformamos infraestruturas analógicas em dispositivos inteligentes de forma acessível (plug-and-play). O diferencial é a **Automação Cruzada Proativa**: os módulos tomam decisões defensivas para garantir segurança ativa, atuando como uma apólice de seguro digital.

---

## 🏗️ Arquitetura do Projeto (A Linha Sense)

### 💧 01. HydroSense (Gestão Hídrica)
Monitoramento inteligente de fluxo para prevenção de inundações e desperdício.
* **Vida Real:** Instalado em pontos de entrada (pias/chuveiros). Utiliza uma **Válvula Solenoide** ou **Atuador de Esfera** para o corte físico.
* **Visão Técnica:** Sensor de **Efeito Hall** que conta pulsos magnéticos gerados por uma turbina interna. O ESP32 calcula a frequência dos pulsos para definir a vazão (L/min).
* **Lógica de Proteção:** Classifica a vazão em Baixa, Normal ou Intensa. Se o fluxo for constante por >30s, o sistema bloqueia a água e aguarda um **Reset Manual** (via botão físico ou App).


### 🔥 02. AeroSense (Segurança Ambiental)
Sentinela contra vazamentos de gás (GLP/Natural) e princípios de incêndio.
* **Vida Real:** Atua no corte preventivo da válvula de gás e comunicação com o EnergySense para evitar faíscas elétricas.
* **Visão Técnica:** Sensor **MQ-2** que altera sua condutividade na presença de gases inflamáveis. O sinal analógico é processado pelo ESP32 em níveis de PPM (Partes por Milhão).
* **Ação:** Alerta sonoro (Buzzer) e visual imediato.

### ⚡ 03. EnergySense (Gestão Energética)
Smart Plugs para controle de consumo e proteção elétrica.
* **Vida Real:** Permite desligar eletrodomésticos remotamente e monitorar gastos reais.
* **Visão Técnica:** Sensor de corrente **ACS712** com isolamento galvânico. Um módulo Relé atua como o interruptor físico controlado pelo microcontrolador.

### 🚪 04. CoreSense (O Cérebro / Painel)
Interface física principal localizada na saída da residência. Permite o acionamento de perfis:
* **Modo Casa:** Funcionamento padrão com monitoramento de fundo.
* **Modo Ausente:** Corta gás preventivamente e desliga tomadas "Não Essenciais" (TVs, cafeteiras).
* **Modo Férias:** Bloqueio total de água e gás com relatórios detalhados via nuvem.

---

## 🚀 Proposta de Valor e Modelo de Negócios
* **Segurança Patrimonial:** Evita perdas severas com inundações ou incêndios.
* **Sustentabilidade (ESG):** Redução drástica do desperdício hídrico e energético.
* **Parcerias com Seguradoras:** Modelo B2B2C onde o cliente ganha descontos na apólice residencial ao possuir o kit instalado.
* **SaaS Analytics:** Dashboard Premium focado em análise de dados cruzados para insights de economia real.

---

## ⚙️ Tecnologias Utilizadas
* **Microcontrolador:** ESP32 (Wi-Fi/Bluetooth nativo)
* **Linguagem:** C++ (Arduino Framework)
* **Simulação:** Wokwi
* **Atuadores:** Micro Servo Motor (Válvulas), Relés, Buzzer.
* **Displays:** OLED SSD1306 (Feedback em tempo real).

---

## 🔗 Links das Simulações (Wokwi)

| Módulo | Link de Acesso | Status |
| :--- | :--- | :--- |
| ⚡ **EnergySense** | [Acessar Projeto](https://wokwi.com/projects/456412173957770241) | ✅ Estável |
| 🔥 **AeroSense** | [Acessar Projeto](https://wokwi.com/projects/456414554766683137) | ✅ Estável |
| 💧 **HydroSense** | [Acessar Projeto](https://wokwi.com/projects/456417552278824961) | ✅ Estável (Timer & Reset) |

---
