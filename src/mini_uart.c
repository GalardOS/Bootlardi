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

#include "mini_uart.h"

#include "io.h"
#include "utils.h"

void muart_printf_send_char(void* p, char c)
{
	muart_send_char(c);
}

void muart_initialize()
{
	unsigned int selector;
	
	selector = mem_get32(GPFSEL1);
	selector &= ~(7 << 12);                   // clean gpio14
	selector |= 2 << 12;                      // set alt5 for gpio14
	selector &= ~(7 << 15);                   // clean gpio15
	selector |= 2 << 15;                      // set alt5 for gpio15
	mem_put32(GPFSEL1, selector);
	
	mem_put32(GPPUD, 0);
	delay(150);
	mem_put32(GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);
	mem_put32(GPPUDCLK0, 0);
	
	mem_put32(AUX_ENABLES, 1);                   // Enable mini uart (this also enables access to it registers)
	mem_put32(AUX_MU_CNTL_REG, 0);               // Disable auto flow control and disable receiver and transmitter (for now)
	mem_put32(AUX_MU_IER_REG, 0);                // Disable receive and transmit interrupts
	mem_put32(AUX_MU_LCR_REG, 3);                // Enable 8 bit mode
	mem_put32(AUX_MU_MCR_REG, 0);                // Set RTS line to be always high
	mem_put32(AUX_MU_BAUD_REG, 270);             // Set baud rate to 115200

	mem_put32(AUX_MU_CNTL_REG, 3);               // Finally, enable transmitter and receiver
}

void muart_send_char(const char character)
{
	while(1) 
	{
		if(mem_get32(AUX_MU_LSR_REG) & 0x20) 
			break;
	}
	mem_put32(AUX_MU_IO_REG, character);
}
