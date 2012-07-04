<Qucs Schematic 0.0.15>
<Properties>
  <View=0,0,1380,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=pump_relay.dat>
  <DataDisplay=pump_relay.dpl>
  <OpenDisplay=1>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.PortSym 40 20 8 0>
</Symbol>
<Components>
  <_BJT 2N3904 1 410 250 8 -26 0 0 "npn" 1 "1e-16" 0 "1" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "100" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0.75" 0 "0.33" 0 "0" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <Relais Relay 1 380 160 -86 -26 0 2 "0.5 V" 0 "0.1 V" 0 "0" 0 "1e12" 0 "26.85" 0>
  <R R1 1 320 250 -26 15 0 0 "1000 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Diode 1N4004 1 520 160 -65 -26 0 3 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <Vdc V3 1 230 130 -26 18 0 0 "12 V" 1>
  <L Pump 1 150 160 -47 -26 0 3 "1 nH" 0 "" 0>
  <Vdc V1 1 550 240 18 -26 0 1 "5 V" 1>
  <Diode LED 1 230 250 -26 -33 0 2 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <GND * 1 550 310 0 0 0 0>
  <Port ArduinoPin8 1 120 250 -23 12 0 0 "8" 0 "analog" 0>
</Components>
<Wires>
  <410 190 410 220 "" 0 0 0 "">
  <410 130 520 130 "" 0 0 0 "">
  <350 250 380 250 "" 0 0 0 "">
  <410 190 520 190 "" 0 0 0 "">
  <260 130 350 130 "" 0 0 0 "">
  <150 190 350 190 "" 0 0 0 "">
  <150 130 200 130 "" 0 0 0 "">
  <550 270 550 310 "" 0 0 0 "">
  <520 130 550 130 "" 0 0 0 "">
  <550 130 550 210 "" 0 0 0 "">
  <260 250 290 250 "" 0 0 0 "">
  <410 280 410 310 "" 0 0 0 "">
  <410 310 550 310 "" 0 0 0 "">
  <120 250 200 250 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
