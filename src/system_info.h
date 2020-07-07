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

#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

typedef struct memory_reservation_entry {
    unsigned long start;
    unsigned long size;
} memory_reservation_entry_t;

typedef struct memory_info {
    unsigned long mem_start;
    unsigned long mem_size;

    int n_reserved_areas;
    memory_reservation_entry_t reserved_areas[20];
} memory_info_t;

typedef struct system_info
{
    memory_info_t memory;
} system_info_t;

#endif // SYSTEM_INFO_H
