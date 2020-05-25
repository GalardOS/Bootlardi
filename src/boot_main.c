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

#include "atags.h"
#include "system_info.h"
#include "printf.h"
#include "mini_uart.h"
#include "mem_utils.h"

int get_info_from_atags(struct atag* atag, struct system_info* out_info)
{
    if(atag->type != CORE)
    {
        printf("[X] Bootloader is not able to read atags\r\n");
        printf("    Reconfigure and restart...\r\n");

        return 1;
    }

    while(atag->type != NONE)
    {
        switch(atag->type)
        {
            case CORE:
            {
                out_info->mem_default_page_size = atag->core.page_size;
            } break;

            case MEMORY:
            {
                out_info->mem_size = atag->memory.size;
                out_info->mem_start = atag->memory.start;
            } break;
            
            case VIDEOTEXT: 
            {

            } break;

            case RAMDISK: 
            {

            } break;

            case INITRD:
            {

            } break;

            case SERIAL:
            {

            } break;

            case REVISION:
            {

            } break;

            case VIDEOFB:
            {

            } break;

            case CMDLINE: 
            {

            } break;
        }

        atag = (struct atag*)(((unsigned int*) atag) + atag->tag_size);
    }

    return 0;
}

void boot_main()
{
    struct atag* atag = (struct atag*) 0x100;

    init_printf(0, muart_printf_send_char);
    printf("[+] Reading system information...\r\n");

    // Get system information and copy to where the kernel expects
    struct system_info info = {};
    get_info_from_atags(atag, &info);
    memcpy(&info, (void*)0x100, sizeof(struct system_info));

    // Print the system information
    printf("    Memory start:      %d\r\n", info.mem_start);
    printf("    Memory size:       %d\r\n", info.mem_size);
    printf("    Memory page size:  %d\r\n", info.mem_default_page_size);
    printf("[+] Done.\r\n");

    while(1);
}
