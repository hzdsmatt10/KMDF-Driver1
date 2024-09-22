#include <ntddk.h>

void ProcessPowerUnload(PDRIVER_OBJECT DriverObject);

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    DbgPrint(("ProcessPower:DriverEntry\n"));
    DbgPrint("Registry path: %wZ\n", RegistryPath);

    // Set the DriverUnload routine
    DriverObject->DriverUnload = ProcessPowerUnload;

    // Get OS version information
    RTL_OSVERSIONINFOW vi = { sizeof(vi) };
    NTSTATUS status = RtlGetVersion(&vi);
    if (!NT_SUCCESS(status)) {
        KdPrint(("Failed in RtlGetVersion(0x%X)\n", status));
        return status;
    }

    // Log the Windows version
    DbgPrint("Windows version: %u.%u.%u\n",
        vi.dwMajorVersion,
        vi.dwMinorVersion,
        vi.dwBuildNumber);

    return STATUS_SUCCESS;
}

void ProcessPowerUnload(PDRIVER_OBJECT DriverObject) {
    DbgPrint(("ProcessPower:Unload\n"));
    UNREFERENCED_PARAMETER(DriverObject);
}