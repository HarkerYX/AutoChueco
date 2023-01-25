#include "Port.h"
#include "Port_Cfg.h"

const Port_ConfigType ConfigArray[ PORT_NUMBER_OF_PORT_PINS ] =
{
{ .PortPinName        = PORT_A0,
  .PortPinInitialMode = PORT_PIN_MODE_DIO,
  .PortPinDirection   = PORT_PIN_OUT,
  .PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
  .PortPinResistor    = PORT_NOPULL,
  .PortPinSpeed       = PORT_SPEED_LOW,
  .PortPinOuputDrive  = PORT_PUSH_PULL } };
