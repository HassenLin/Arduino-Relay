#ifndef RELAY_H
#define RELAY_H
class Relay{
  private:
    int m_pinNum;
  public:
    bool m_Level;
    Relay(int PinNum);
    void SetLevel(int Level);
};
#endif
