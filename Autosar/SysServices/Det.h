/**
 * @file    Det.h
 * @brief   **Specification of Default Error Trace**
 *
 * The Default Error Tracer provides functionality to support error detection and tracing of errors
 * during the development and runtime of Software Components and other Basic Software Modules. For
 * this purpose the Default Error Tracer receives and evaluates error messages from these components
 * and modules.
 *
 * Due to the always specific (non generic!) requirements regarding functionality in error cases
 * there is no explicit specification of the DET implementation, except:
 *
 * - Configurable lists of error hooks will be executed in case of an error report.
 * - Interfaces will be provided to report errors, allow optional error recovery after reset, to handle
 *   optional error recovery information and to retrieve version information.
 */
#ifndef DET_H
#define DET_H

/**
 * @brief Configuration data structure for Det.
 *
 */
typedef struct Det_ConfigType_Tag
{
    uint8 Dummy; /**< dummi paramter to avoid warnings*/
} Det_ConfigType;

void Det_Init( const Det_ConfigType *ConfigPtr );
void Det_Start( void );
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorID );
Std_ReturnType Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorID );
Std_ReturnType Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorID );

#endif /* DET_H */
