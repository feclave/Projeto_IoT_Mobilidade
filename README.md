# Projeto_IoT_Mobilidade

Problema:

Imagine um sistema de transporte público em que os ônibus frequentemente param em pontos de parada que não possuem plataformas elevadas para auxiliar pessoas com mobilidade reduzida a embarcar e desembarcar. Essas pessoas enfrentam dificuldades para subir e descer dos ônibus, especialmente em horários de pico, quando há aglomeração.

Solução:

Utilizando a placa ESP32 e o sensor ultrassônico HC-SR04, podemos desenvolver um sistema que auxilie na identificação de obstáculos e na geração de alertas para os motoristas, permitindo que eles se aproximem dos pontos de parada de forma mais segura e precisa.

Funcionamento:

o Instalação: A placa ESP32 com o sensor HC-SR04 seria instalada na parte frontal do ônibus, direcionado para a área onde os passageiros embarcam e desembarcam.

o Detecção de Obstáculos: O sensor ultrassônico constantemente medirá a distância até os obstáculos à frente do ônibus.

o Alerta Visual: Um LED pequeno seria acionado para indicar ao motorista que há um obstáculo próximo.

o Alerta Sonoro: Um ‘buzzer’ ou sinal sonoro seria emitido para chamar a atenção do motorista.

o Configuração de Distância: O sistema poderia ser configurado para gerar alertas em diferentes distâncias.

o Comunicação: A placa ESP32 poderia se conectar a um aplicativo móvel para que os operadores do transporte público possam monitorar os ônibus em tempo real e receber notificações sobre possíveis problemas.

Benefícios:

o Maior segurança: Reduz o risco de acidentes envolvendo pessoas com mobilidade reduzida.

o Melhoria na acessibilidade: Facilita o embarque e desembarque de passageiros com dificuldades de locomoção.

o Otimização das paradas: Permite que os motoristas se aproximem dos pontos de parada de forma mais precisa, reduzindo o tempo de parada e aumentando a eficiência do sistema.

o Dados para análise: Os dados coletados pelo sensor podem ser utilizados para analisar o comportamento dos passageiros e identificar pontos críticos do sistema.

Considerações Adicionais:

o Alimentação: A placa ESP32 pode ser alimentada pela bateria do ônibus ou por uma fonte externa.

o Comunicação: Além do Bluetooth, outras opções de comunicação como Wi-Fi ou LoRa podem ser utilizadas, dependendo da infraestrutura disponível.