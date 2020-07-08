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
#include "dtb.h"

void boot_main(long x0, long x1, long x2)
{
    init_printf(0, muart_printf_send_char);

    printf("[+] Reading system information...\r\n");
    
    // 0x100 is the address where the bootloader loads the dtb file contents
    /// TODO: get the dtb address from x2 register rather than hardcoded
    void* dtb_addr = (void*)0x100;
    
    if(dtb_verify(dtb_addr)) {
        printf("    DTB found!\n");
        /// TODO: do dtb things
    } else {
        printf("    DTB not found!\n");
        /// TODO: check atags
    }

    while(1);
}
