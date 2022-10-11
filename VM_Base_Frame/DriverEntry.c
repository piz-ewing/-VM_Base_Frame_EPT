/************************************************************************/
/*                     This Is VM_Base_Frame                            */
/************************************************************************/

//
// ����ļ�������Ϊ����ļ�
//
#include "stdafx.h"

VOID unload_drv(_In_ struct _DRIVER_OBJECT *DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);
	if (NT_SUCCESS(!VMXSTOP()))
	{
		KdPrint(("-[VM-Base-Frame]- : ж�سɹ�,���������쳣!\n"));
	}
}

//************************************
// Method:    DriverEntry
// FullName:  DriverEntry
// Access:    public
// Returns:   NTSTATUS
// Qualifier:
// Parameter: _In_ PDRIVER_OBJECT DriverObject
// Parameter: _In_ PUNICODE_STRING RegistryPath
// Remark:
//************************************
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject,	_In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	VMXSTART();
	DriverObject->DriverUnload = unload_drv;

	return STATUS_SUCCESS;
}