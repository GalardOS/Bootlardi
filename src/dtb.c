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

typedef struct dtb_header {
    int magic;
    int total_size;
    int off_dt_struct;
    int off_dt_strings;
    int off_mem_rsvmap;
    int version;
    int last_comp_version;
    int boot_cpuid_phys;
    int size_dt_strings;
    int size_dt_struct;
};

int get_is_dtb_file(void* dtb_addr) {
    struct dtb_header* header = (struct dtb_header*)dtb_addr;
    return header->magic != -302117424;
}