# 🪁 Projeto Kite: Ecossistema de Retrofit Inteligente

> **Segurança, Sustentabilidade e Inteligência Integrada através de Retrofit.**
> Projeto desenvolvido pela **AnGa RetroTechfit** para a disciplina de *Project-based Maker Lab* (4º Ano - Engenharia de Software | FIAP).

👨‍💻 **Autores:** Anna Heloisa Soto Yagyu e Gabriel Pacheco

---

## 🚨 O Problema
O mercado atual de *Smart Homes* enfrenta três grandes barreiras:
1. **O Custo da Modernização:** Eletrodomésticos com conectividade nativa (IoT) possuem preços proibitivos.
2. **Desperdício Invisível:** O "consumo fantasma" e vazamentos silenciosos de água geram impacto financeiro e ecológico constante.
3. **Reação vs. Prevenção:** Soluções comuns apenas notificam. No Kite, o sistema **age** antes que o dano patrimonial ocorra.

## 💡 A Solução: Ecossistema Kite
O Kite é um kit de **Retrofit Residencial**. Transformamos infraestruturas analógicas em dispositivos inteligentes de forma acessível (plug-and-play). O diferencial é a **Automação Cruzada Proativa**: se o gás vaza, o sistema corta a energia para evitar faíscas. Se a água corre por muito tempo, o registro é fechado preventivamente.

---

## 🏗️ Arquitetura do Projeto (A Linha Sense)

### 💧 01. HydroSense (Gestão Hídrica)
Monitoramento inteligente de fluxo para prevenção de inundações.
* **Hardware:** Sensor de Fluxo (Efeito Hall), Servo Motor (Válvula) e Botão de Reset.
* **Visão Técnica:** Utiliza temporizadores (`millis()`) para detectar anomalias. Se a vazão (baixa, normal ou intensa) persistir por mais de **30 segundos**, o sistema corta o suprimento.
* **Diferencial:** Possui **Manual Override** via botão físico, permitindo que o morador restabeleça o fluxo localmente após verificar a segurança.


### 🔥 02. AeroSense (Segurança Ambiental)
Sentinela contra vazamentos de gás (GLP/Natural) e princípios de incêndio.
* **Hardware:** Sensor MQ-2, Display OLED, Buzzer e Servo Motor.
* **Visão Técnica:** O sistema processa o nível de PPM (Partes por Milhão) em tempo real. 
* **Ação Ativa:** Ao ultrapassar o limite de segurança (~1500 no simulador), o OLED exibe um alerta crítico, o alarme sonoro é disparado e a válvula de gás é fechada instantaneamente pelo servo motor.

### ⚡ 03. EnergySense (Gestão Energética)
Smart Plugs para controle de consumo e proteção elétrica.
* **Hardware:** Sensor de corrente ACS712 e Módulo Relé.
* **Função:** Monitora o consumo em Amperes e permite o tagueamento de aparelhos como "Essencial" ou "Não Essencial", permitindo cortes inteligentes em situações de risco.

### 🚪 04. CoreSense (O Cérebro / Painel) - *Em Desenvolvimento*
Interface física central para controle de perfis de usuário:
* **Modo Casa:** Monitoramento padrão.
* **Modo Ausente:** Automação proativa (Corte de gás e tomadas não essenciais).
* **Modo Férias:** Bloqueio total de infraestrutura (água e gás) com relatórios remotos.

---

## 🚀 Próximos Passos: Software & Integração

### 📱 Aplicativo e Dashboard AnGa
Estamos desenvolvendo uma interface centralizada que permitirá:
1. **Controle Remoto:** Abrir/Fechar válvulas e tomadas de qualquer lugar.
2. **Histórico de Consumo:** Gráficos detalhados de gasto hídrico e elétrico para análise ESG.
3. **Notificações Push:** Alertas em tempo real de vazamentos ou picos de consumo.

### 🔗 Integração em Nuvem
Utilização de protocolos **MQTT/HTTP** para conectar os 4 dispositivos a um Broker central, permitindo que os sensores "conversem" entre si sem necessidade de fiação adicional.

---

## ⚙️ Tecnologias Utilizadas
* **Microcontrolador:** ESP32 (Wi-Fi/Bluetooth nativo)
* **Linguagem:** C++ (Arduino Framework)
* **Simulação:** Wokwi
* **Displays:** OLED SSD1306 (I2C)

---

## 🔗 Links das Simulações (Wokwi)

| Módulo | Link de Acesso | Status |
| :--- | :--- | :--- |
| ⚡ **EnergySense** | [Acessar Projeto](https://wokwi.com/projects/456412173957770241) | ✅ Estável |
| 🔥 **AeroSense** | [Acessar Projeto](https://wokwi.com/projects/456414554766683137) | ✅ v2.0 (OLED & Corte) |
| 💧 **HydroSense** | [Acessar Projeto](https://wokwi.com/projects/456417552278824961) | ✅ v2.2 (Timer & Reset) |

---
