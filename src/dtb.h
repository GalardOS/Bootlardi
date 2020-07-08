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
 * Authors:d
 *    - Iker Galardi
 */

#ifndef DTB_H
#define DTB_H

#include "system_info.h"

/// Vefifies that a compatible dtb file is located on the address
///     dtb_addr: address where the dtb file resides
///     return: 0 if there is a dtb file, 1 if not
int dtb_verify(void* dtb_addr);

/// Fills the array of reserved entries and returns how many entries where found
///     dtb_addr: address where the dtb file resides
///     entry_array: the pointer to the first element of the entries array
///     return: number of reserved memory areas, -1 when too much reserved areas
int dtb_get_reserved_areas(void* dtb_addr, memory_reservation_entry_t* array);

#endif // DTB_H