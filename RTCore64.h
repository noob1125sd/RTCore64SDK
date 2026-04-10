#pragma once
#define RTCORE64_IOC_READ_PORT          0x80002008
#define RTCORE64_IOC_WRITE_PORT         0x8000200C
#define RTCORE64_IOC_READ_PORT_WORD     0x80002010
#define RTCORE64_IOC_WRITE_PORT_WORD    0x80002014
#define RTCORE64_IOC_READ_PORT_DWORD    0x80002018
#define RTCORE64_IOC_WRITE_PORT_DWORD   0x8000201C
#define RTCORE64_IOC_READ_MSR           0x80002030
#define RTCORE64_IOC_WRITE_MSR          0x80002034
#define RTCORE64_IOC_READ_MEM           0x80002048
#define RTCORE64_IOC_WRITE_MEM          0x8000204C
#define RTCORE64_IOC_READ_PCI           0x80002050
#define RTCORE64_IOC_WRITE_PCI          0x80002054

#pragma pack(push, 1)

struct RTCORE64_PORT_IO {
    uint32_t Address = 0;
    uint32_t Data=0;
    uint32_t Size=0;
};

struct RTCORE64_MSR_IO {
    uint32_t Register=0;
    uint32_t ValueHigh=0;
    uint32_t ValueLow=0;
};

struct RTCORE64_MEM_IO {
    uint64_t Pad0=0;
    uint64_t Address=0;
    uint32_t Pad1=0;
    uint32_t Data=0;
    uint32_t Size=0;
    uint32_t Pad2=0;
};

struct RTCORE64_PCI_IO {
    uint32_t Bus=0;
    uint32_t Device=0;
    uint32_t Function=0;
    uint32_t Offset=0;
    uint32_t Data=0;
    uint32_t Size=0;
};

#pragma pack(pop)
#include <windows.h>

namespace RTDriver {
    inline HANDLE Open() {
        return CreateFileA(
            "\\\\.\\RTCore64",
            GENERIC_READ | GENERIC_WRITE,
            0,
            nullptr,
            OPEN_EXISTING,
            0,
            nullptr
        );
    }
}
