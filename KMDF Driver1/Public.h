/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_KMDFDriver1,
    0xb41bd954,0xd022,0x4be9,0x95,0x01,0x53,0x9e,0x34,0xb4,0x91,0x27);
// {b41bd954-d022-4be9-9501-539e34b49127}
