import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
int serialValue;
int[] yPos;

void setup () {
  // set the window size:
  size(1024, 1024);

  // List all the available serial ports
  // if using Processing 2.1 or later, use Serial.printArray()
  println(Serial.list());

  // I know that the first port in the serial list on my Mac is always my
  // Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 9600);

  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');

  // set initial background:
  background(0);
  yPos = new int[width];
}

void draw () {
  background(0);
  strokeWeight(1);
  stroke(255, 255, 0, 120);
  for (int i=0;i < width; i+=50)
    line(i, 0, i, height);
  for (int i=0;i < height; i+=50)
    line(0, i, width, i);

  stroke(255,0,0);
  strokeWeight(5);
  int yPosPrev = 0, xPosPrev = 0;
  println(serialValue);
  // Décaler les valeurs du tableau vers la gauche
  for (int x=1;x<width;x++)
    yPos[x-1] = yPos[x];
  // Joindre les nouvelles coordonnées de la souris à l'extrémité droite du tableau
  yPos[width-1] = serialValue;
  // Affichage du tableau
  for (int x = 0; x < width; x++) {
    if (x>0)
      line(xPosPrev,yPosPrev,x,yPos[x]);
    xPosPrev = x;       // Stockage de la dernière position x
    yPosPrev = yPos[x]; // Stockage de la dernière position y
  }
}

void serialEvent (Serial myPort) {
  String portStream = myPort.readString();
  float data = float(portStream);
  serialValue = height - (int)map(data, 0, 1023, 0, height);
}
