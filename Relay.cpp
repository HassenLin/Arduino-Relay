#include "Relay.h"
#include <inttypes.h>
#include <Arduino.h>
Relay::Relay(int PinNum) : m_pinNum(PinNum)
{
 pinMode(m_pinNum, OUTPUT);
 digitalWrite(m_pinNum, 0);

}
void Relay::SetLevel(int Level)
{
  digitalWrite(m_pinNum,Level);
  m_Level=Level;
}