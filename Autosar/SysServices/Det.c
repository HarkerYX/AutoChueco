/**
 * @file    Det.c
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
#include "Std_Types.h"
#include "Det.h"


/**
 * @brief   Initializes the Det Driver module with the configuration set pointed to by ConfigPtr.
 *
 * @param[in]  ConfigPtr  Pointer to the configuration set to be used for initialization.
 *
 * @code
 *      Det_Init( &DetConfiguration );
 * @endcode
 */
void Det_Init( const Det_ConfigType *ConfigPtr )
{
    (void)ConfigPtr;
}

/**
 * @brief   **Service to start the Default Error Tracer**.
 *
 * @code
 *      Det_Start( );
 * @endcode
 */
void Det_Start( void )
{
}

/**
 * @brief   **Service to report development errors.**
 *
 * Det_ReportError may be callable in interrupt context. Since the DET can be called in normal mode
 * or in interrupt context (from stack or integration) this has to be considered during implementation
 * of the hook functions: Det_ReportError can be called in interrupt context; this should be considered
 * when halting the system.
 *
 * @param[in]  ModuleId  Module ID of calling module.
 * @param[in]  InstanceId  The identifier of the index based instance of a module, starting from 0,
 *                          If the module is a single instance module it shall pass 0 as the InstanceId
 * @param[in]  ApiId  ID of API service in which error is detected (defined in SWS of calling module)
 * @param[in]  ErrorID  D of detected development error (defined in SWS of calling module).
 *
 * @retval never returns a value, but has a return type for compatibility with services and hooks
 *
 * @code
 *      Det_ReportError( &DetConfiguration );
 * @endcode
 */
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorID )
{
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorID;

    return 0u;
}

/**
 * @brief   **Service to report runtime errors**
 *
 * Service to report runtime errors. If a callout has been configured then this callout shall be
 * called.
 *
 * @param[in]  ModuleId  Module ID of calling module.
 * @param[in]  InstanceId  The identifier of the index based instance of a module, starting from 0,
 *                          If the module is a single instance module it shall pass 0 as the InstanceId
 * @param[in]  ApiId  ID of API service in which error is detected (defined in SWS of calling module)
 * @param[in]  ErrorID  D of detected development error (defined in SWS of calling module).
 *
 * @retval returns always E_OK (is required for services)
 *
 * @code
 *      Det_ReportRuntimeError( &DetConfiguration );
 * @endcode
 */
Std_ReturnType Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorID )
{
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorID;

    return 0u;
}

/**
 * @brief   **Service to report transient faults**
 *
 * Service to report transient faults. If a callout has been configured than this callout shall be
 * called and the returned value of the callout shall be returned. Otherwise it returns immediately
 * with E_OK.
 *
 * @param[in]  ModuleId  Module ID of calling module.
 * @param[in]  InstanceId  The identifier of the index based instance of a module, starting from 0,
 *                          If the module is a single instance module it shall pass 0 as the InstanceId
 * @param[in]  ApiId  ID of API service in which error is detected (defined in SWS of calling module)
 * @param[in]  ErrorID  D of detected development error (defined in SWS of calling module).
 *
 * @retval If no callout exists it shall return E_OK, otherwise it shall return the value of the
 *          configured callout. In case several callouts are configured the logical or (sum) of
 *          the callout return values shall be returned. Rationale: since E_OK, E_OK will be only
 *          returned if all are E_OK, and for multiple error codes there is a good chance to detect
 *          several of them
 *
 * @code
 *      Det_ReportTransientFault( &DetConfiguration );
 * @endcode
 */
Std_ReturnType Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorID )
{
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorID;

    return 0u;
}
