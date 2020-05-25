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

.section ".text.boot"

.globl _start
_start:
	// Check if its the primary cpu, if not hang
	mrs	x0, mpidr_el1		
	and	x0, x0, #0xFF
	cbnz	x0, boot_hang

	// set the bss region to 0	
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0 
memzero: 
	str	xzr, [x0], #8
	subs	x1, x1, #8
	bgt 	memzero

	// set the stack pointer and start bootloader
	mov	x0, #0x8000
	mov	x1, #2
	mul	x0, x0, x1
	mov	sp, x0 

	// Pass the atags address
	mov x2, x0	
	bl	boot_main

boot_hang: 
	b	boot_hang

