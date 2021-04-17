#define COLUMN_PIN_COUNT 9
#define LAYER_COUNT 3

int Columns[] = {10,9,8,7,6,5,4,3,2};
int Layers[] = {A2,A1,A0};

int i, j, num;
int delaySpeed = 70;

void setup()
{
    for (i = 0; i < LAYER_COUNT; i++)
    {
      pinMode(Layers[i], OUTPUT);
    }
  
    for (i = 2; i <= 10; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    //first combination
      num = 0;
      while(num < LAYER_COUNT - 1)
      {
          for (i = 0; i < LAYER_COUNT; i++)
          {
              digitalWrite(Layers[i], HIGH);
              for (j = 0; j < COLUMN_PIN_COUNT; j++)
            { 
                  startingLEDOneByOne(j);
              }
              digitalWrite(Layers[i], LOW);
          }
          num++;
      }
  
      closeLayerForUse();
  
    
      //second combination
      num = 0;
      while(num < LAYER_COUNT - 1)
      {
          for(i = LAYER_COUNT; i > -1; i--)
          {
            digitalWrite(Layers[i], LOW);
          }
          for(i = 0; i < COLUMN_PIN_COUNT; i++)
            {
            digitalWrite(Columns[i], HIGH); 
          }
          for(i = 0; i < LAYER_COUNT; i++)
          {
            digitalWrite(Layers[i], HIGH);
            delay(delaySpeed);          
          }
          for(i = LAYER_COUNT; i > -1; i--)
          {
            digitalWrite(Layers[i], LOW);
          }
          num++;
      }
  
      //third combination  
      delay(delaySpeed * 8);
      startLayerForUse();
      num = 0;
      while(num < LAYER_COUNT)
      {
          for(i = 0; i < COLUMN_PIN_COUNT; i++)
          {
              digitalWrite(Columns[i],HIGH);
              delay(delaySpeed);
              digitalWrite(Columns[i],LOW);
              delay(delaySpeed);
          }
          num++;
      }
      closeLayerForUse();
  
      //forth combination  
      num = 0;
      while(num < LAYER_COUNT)
      {
        for( i = 0; i < LAYER_COUNT; i++)
        {
            switch(i)
            {
                case 0:
                    startLayerForUse();
  
                    delay(delaySpeed * 5);
  
                    digitalWrite(Columns[0],HIGH);
                    delay(delaySpeed);
                    digitalWrite(Columns[8],HIGH);
                    digitalWrite(Columns[1],HIGH);
                    delay(delaySpeed);
                    digitalWrite(Columns[7],HIGH);
                    digitalWrite(Columns[8],HIGH);
                    digitalWrite(Columns[2],HIGH);
                    delay(delaySpeed);
                    digitalWrite(Columns[4],HIGH);
                    digitalWrite(Columns[5],HIGH);
                    digitalWrite(Columns[3],HIGH);
                    delay(delaySpeed);
                    digitalWrite(Columns[8],HIGH);
                    digitalWrite(Columns[4],HIGH);
                    digitalWrite(Columns[1],HIGH);
                    delay(delaySpeed);
                    digitalWrite(Columns[7],HIGH);
                    digitalWrite(Columns[5],HIGH);
                    delay(delaySpeed);
                    digitalWrite(Columns[6],HIGH);
                    delay(delaySpeed);
  
                    digitalWrite(Columns[6],LOW);
                    delay(delaySpeed);
                    digitalWrite(Columns[7],LOW);
                    digitalWrite(Columns[5],LOW);
                    delay(delaySpeed);
                    digitalWrite(Columns[8],LOW);
                    digitalWrite(Columns[4],LOW);
                    digitalWrite(Columns[1],LOW);
                    delay(delaySpeed);
                    digitalWrite(Columns[4],LOW);
                    digitalWrite(Columns[5],LOW);
                    digitalWrite(Columns[3],LOW);
                    delay(delaySpeed);
                    digitalWrite(Columns[7],LOW);
                    digitalWrite(Columns[8],LOW);
                    digitalWrite(Columns[2],LOW);
                    delay(delaySpeed);
                    digitalWrite(Columns[8],LOW);
                    digitalWrite(Columns[1],LOW);
                    delay(delaySpeed);
                    digitalWrite(Columns[0],LOW);
                    delay(delaySpeed);
  
                    closeLayerForUse();
                    break;
  
              case 1:
                    closeLayerForUse();
                    startLEDWithoutIndex();
  
                    delay(delaySpeed * 3);
                    digitalWrite(Layers[3],HIGH);
                    delay(delaySpeed * 3);
                    digitalWrite(Layers[3],LOW);
                    digitalWrite(Layers[2],HIGH);
                    delay(delaySpeed * 3);
                    digitalWrite(Layers[2],LOW);
                    digitalWrite(Layers[1],HIGH);
                    delay(delaySpeed * 3);
                    digitalWrite(Layers[1],LOW);
                    digitalWrite(Layers[0],HIGH);
                    delay(delaySpeed * 3);
                    digitalWrite(Layers[0],LOW);
                    delay(delaySpeed * 3);
  
                    startLayerForUse();
                    stopLEDWithoutIndex();
                    break;
              case 2:
                    delay(delaySpeed * 6);
                    startLEDWithoutIndex();
                    delay(delaySpeed * 4);
                    stopLEDWithoutIndex();          
                    delay(delaySpeed * 4);
                    for(i = LAYER_COUNT; i < COLUMN_PIN_COUNT;i++)
                    {
                        digitalWrite(Columns[i],HIGH); 
                    }
                    delay(delaySpeed * 4);
                    for(i = LAYER_COUNT; i < COLUMN_PIN_COUNT; i++)
                    {
                        digitalWrite(Columns[i],LOW);
                    }
                    break;
              }
            num++;
          }
      }
      //third combination again
      delay(delaySpeed * 8);
      startLayerForUse();
      num = 0;
      while(num < LAYER_COUNT)
      {
          for(i = 0; i < COLUMN_PIN_COUNT; i++)
          {
              digitalWrite(Columns[i],HIGH);
              delay(delaySpeed);
              digitalWrite(Columns[i],LOW);
              delay(delaySpeed);
          }
        num++;
      }
      closeLayerForUse();
}

void startingLEDOneByOne(int LedIndex) 
{
    digitalWrite(Columns[LedIndex], HIGH);
    delay(delaySpeed);
    digitalWrite(Columns[LedIndex], LOW);
    delay(delaySpeed);
}

void startLayerForUse()
{
    for (i = 0; i < LAYER_COUNT; i++)
    {       
        digitalWrite(Layers[i], HIGH);
    }
}

void closeLayerForUse()
{
    for (i = 0; i < LAYER_COUNT; i++)
    {       
        digitalWrite(Layers[i], LOW);
    }
}

void startLEDWithoutIndex()
{
  for(i = 0; i < COLUMN_PIN_COUNT; i++)
    {
      digitalWrite(Columns[i],HIGH); 
    }
}
      
void stopLEDWithoutIndex()
{
  for(i = 0; i < COLUMN_PIN_COUNT; i++)
    {
      digitalWrite(Columns[i],LOW); 
    }
}
