### Monitoramento e regulação do ritmo cardíaco via estimulação do nervo vago.

<i>Grupo 8</i>

Breves considerações:

- <i>Nome do projeto:</i> Monitoramento e regulação do ritmo cardíaco via estimulação do nervo vago.
- <i>Sinal de entrada:</i> Sinal eletrofisiológico do ECG do paciente, suficiente para averiguar a frequência cardíaca (FC).
- <i>Sinal de saída:</i> Pulso elétrico monopolar de 5 V + para ativação (trigger) de eletroestimulador de terceiro.
- <i>Interface com o usuário:</i> Será possível interagir via web para analisar o histórico de registros (FC e eventos de estimulação) e também para alterar parâmetros de gatilho e estimulação.
- <i>Informações do relatório Online:</i> Arquivo CSV com o histórico de medições dos intervalos RR, das FCs calculadas e dos momentos de estimulação, todos com identificação de hora e data; gráfico exibindo FC (batimentos por minuto, bpm, eixo vertical) por tempo (a determinar intervalo e unidade, eixo horizontal) bem como traços verticais indicando o momento da estimulação; e relatório ou tabela exibindo o motivo de origem de cada estimulação (uma linha para cada evento de estimulação).
- <i>Gatilho para o alarme:</i> Taquicardia identificada no paciente (FC > 100 bpm).

<div style="text-align: justify;">O projeto “Monitoramento e regulação do ritmo cardíaco via estimulação do nervo vago” visa desenvolver um dispositivo que monitore a FC de seu usuário através do ECG e mantenha um registro da FC e dos intervalos R-R usados 
  para calcular a FC. Caso o dispositivo identifique que a FC é equivalente a uma taquicardia (> 100 bpm), ele deverá acionar um alarme que ativará a unidade de estimulação elétrica do nervo vago (Vagus Nerve Stimulator, VNS, de terceiro) através de pulsos
  monofásicos enviados pelo dispositivo a entrada de trigger do VNS. Os eventos de estimulação, tal como o momento e o protocolo utilizado (frequência de estimulação e duração), também serão registrados para posterior análise. Dessa maneira, espera-se obter 
  uma diminuição da FC devido à estimulação do nervo vago, de forma a evitar que a taquicardia se estenda e resulte em deterioração da função cardíaca, e disponibilizar ao profissional da saúde informações mais precisas sobre a incidência desse evento no 
  paciente (frequência, momentos de início etc).</div>
