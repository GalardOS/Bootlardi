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

#include "common.h"

#define INFORMATION_STATUS_OK               0
#define INFORMATION_STATUS_NO_STRUCTURE     1
#define INFORMATION_STATUS_INFO_MISSING     2

struct system_info
{
    unsigned char info_status;
    
    // Memory related information
    unsigned int mem_start;
    unsigned int mem_size;
    unsigned int mem_default_page_size;

    unsigned int mem_reserved_start;
    unsigned int mem_reserved_size; 
} ATTRIBUTE_PACKED;


#endif // SYSTEM_INFO_H
