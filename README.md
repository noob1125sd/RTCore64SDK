# RTCore64SDK
A specialized C++ Software Development Kit (SDK) designed for low-level system research and interaction with the **RTCore64.sys** driver. This SDK provides a structured interface for kernel-mode operations, focusing on memory management and hardware communication.

## Key Capabilities
* **Memory Management:** Robust interface for Reading/Writing physical memory via IOCTL.
* **Port I/O Operations:** Support for Byte (8-bit), Word (16-bit), and Dword (32-bit) communication.
* **MSR Interface:** Access to Model-Specific Registers (ValueHigh/ValueLow).
* **PCI Configuration:** Direct interaction with PCI bus devices, functions, and offsets.
* **Integrated Deployment:** Embedded driver binary (`driver_data.h`) for portable research tools.

## Technical Implementation
The SDK utilizes precise memory alignment to ensure binary compatibility with kernel-mode buffers. All communication structures are byte-aligned using `#pragma pack(push, 1)` to prevent padding issues during IOCTL dispatch.

```cpp
// Example of the aligned memory structure for physical R/W
#pragma pack(push, 1)
struct RTCORE64_MEM_IO { 
    uint64_t Pad0; 
    uint64_t Address; 
    uint32_t Pad1; 
    uint32_t Data; 
    uint32_t Size; 
    uint32_t Pad2;
};
#pragma pack(pop)
```
Repository Structure
RTCore64.h: Primary header containing IOCTL codes, namespaces, and core structures.

RTCore64Data.h: Hexadecimal representation of the RTCore64.sys binary.

Usage & Disclaimer
This project is intended strictly for educational, research, and security auditing purposes.

The author (🥝) does not condone illegal activities and is not responsible for any system instability, data loss, or hardware damage resulting from the use of this SDK. Interacting with kernel-mode drivers carries inherent risks to system integrity.

License
Distributed under the GNU General Public License v3.0. See LICENSE for more information.
