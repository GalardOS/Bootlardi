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

#include "dtb.h"

#include "utils.h"

#define DTB_MAGIC_NUMBER_BIG_ENDIAN 0xd00dfeed
#define DTB_MAGIC_NUMBER_LITTLE_ENDIAN BYTESWAP32(DTB_MAGIC_NUMBER_BIG_ENDIAN) 

typedef struct dtb_header {
    unsigned int magic;
    unsigned int total_size;
    unsigned int off_dt_struct;
    unsigned int off_dt_strings;
    unsigned int off_mem_rsvmap;
    unsigned int version;
    unsigned int last_comp_version;
    unsigned int boot_cpuid_phys;
    unsigned int size_dt_strings;
    unsigned int size_dt_struct;
} dtb_header_t;

int dtb_verify(void* dtb_addr) {
    dtb_header_t* header = (dtb_header_t*)dtb_addr;
    return header->magic == DTB_MAGIC_NUMBER_LITTLE_ENDIAN || header->magic == DTB_MAGIC_NUMBER_BIG_ENDIAN;
}