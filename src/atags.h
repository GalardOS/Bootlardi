/*
 * This project is provided under the GNU GPL v2 license, more information can 
 * found on https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    - Iker Galardi
 */

#ifndef ATAGS_H
#define ATAGS_H

#include "common.h"

enum atag_type 
{
    NONE = 0x00000000,
    CORE = 0x54410001,
    MEMORY = 0x54410002,
    VIDEOTEXT = 0x54410003,
    RAMDISK = 0x54410004,
    INITRD = 0x54410005,
    SERIAL = 0x54410006,
    REVISION = 0x54410007,
    VIDEOFB = 0x54410008,
    CMDLINE = 0x54410009
};

struct atag_memory
{
    unsigned int size;
    unsigned int start;
} ATTRIBUTE_PACKED;

struct atag_core
{
    unsigned int flags;
    unsigned int page_size;
    unsigned int root_device_number;
} ATTRIBUTE_PACKED;

struct atag 
{
    unsigned int tag_size;
    enum atag_type type;
    
    union
    {
        struct atag_memory memory;
        struct atag_core core;
    };
    
} ATTRIBUTE_PACKED;

#endif // ATAGS_H
