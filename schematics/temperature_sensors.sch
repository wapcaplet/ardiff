<Qucs Schematic 0.0.15>
<Properties>
  <View=0,0,800,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=temperature_sensors.dat>
  <DataDisplay=temperature_sensors.dpl>
  <OpenDisplay=1>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.PortSym 40 20 1 0>
  <.PortSym 50 50 2 0>
</Symbol>
<Components>
  <R R1 1 250 240 -26 15 0 0 "4700 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Port ArduinoDigitalPin3 1 120 170 -23 12 0 0 "1" 0 "analog" 0>
  <Port Arduino5V 1 120 240 -23 12 0 0 "2" 0 "analog" 0>
  <GND * 1 100 300 0 0 0 0>
</Components>
<Wires>
  <280 240 320 240 "" 0 0 0 "">
  <320 240 430 240 "" 0 0 0 "">
  <430 150 430 240 "" 0 0 0 "">
  <410 150 410 180 "" 0 0 0 "">
  <410 300 560 300 "" 0 0 0 "">
  <410 180 410 300 "" 0 0 0 "">
  <410 180 450 180 "" 0 0 0 "">
  <450 150 450 180 "" 0 0 0 "">
  <560 150 560 180 "" 0 0 0 "">
  <560 180 600 180 "" 0 0 0 "">
  <600 150 600 180 "" 0 0 0 "">
  <430 240 580 240 "" 0 0 0 "">
  <580 150 580 240 "" 0 0 0 "">
  <560 180 560 300 "" 0 0 0 "">
  <410 300 410 300 "" 0 0 0 "">
  <320 170 320 240 "" 0 0 0 "">
  <120 170 320 170 "" 0 0 0 "">
  <120 240 220 240 "" 0 0 0 "">
  <100 300 410 300 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
  <Rectangle 390 100 80 50 #000000 0 1 #c0c0c0 1 1>
  <Rectangle 540 100 80 50 #000000 0 1 #c0c0c0 1 1>
  <Text 400 110 10 #000000 0 "DS18B20\nTank">
  <Text 550 110 10 #000000 0 "DS18B20\nCollector">
</Paintings>
