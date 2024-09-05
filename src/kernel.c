char* vgaBuffer = (char*) 0xb8000; // screen buffer (VGA Text Mode)

#define VGA_HEIGHT 25 // corrected screen height
#define VGA_WIDTH 80  // corrected screen width

#define COLOR_GREEN 0x02 // Green color
#define COLOR_BLUE  0x01 // Blue color

// Clears the screen
void terminal_clear_screen(void);

// Function to print a character at a specific position with a specific color
void print_char_at(char c, int row, int col, char color);

// Function to print a string starting at a specific position with a specific color
void print_string(const char *str, int row, int col, char color);

void kernel_main(void)
{
    terminal_clear_screen();

    // Center "NoorOS" in the middle of the screen
    int centerRow = VGA_HEIGHT / 2;
    int centerCol = (VGA_WIDTH / 2) - 3; // 6 characters / 2

    // Print "Noor" in green
    print_string("Noor", centerRow, centerCol, COLOR_GREEN);

    // Print "OS" in blue
    print_string("OS", centerRow, centerCol + 4, COLOR_BLUE); 
}

void terminal_clear_screen(void)
{
    int limit = (VGA_WIDTH * 2) * (VGA_HEIGHT); 
    for (int i = 0; i < limit; ++i) {
        vgaBuffer[i] = 0;
    }
}

void print_char_at(char c, int row, int col, char color) {
    int pos = (row * VGA_WIDTH + col) * 2; // Calculate position in VGA buffer
    vgaBuffer[pos] = c;           // Set character
    vgaBuffer[pos + 1] = color;   // Set color
}

void print_string(const char *str, int row, int col, char color) {
    while (*str) {
        print_char_at(*str, row, col, color);
        col++; // Move to next column
        str++;
    }
}
