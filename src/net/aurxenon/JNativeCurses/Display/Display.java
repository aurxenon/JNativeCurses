package net.aurxenon.JNativeCurses.Display;

public class Display {

    public Display(){}

    public native void displayInit();

    public native void clearScreen();

    private native void nativeDrawCharacter(char character, int x, int y, int backgroundColor, int foregroundColor);
    private native void nativeDrawText(String text, int x, int y, int backgroundColor, int foregroundColor);
    public native void finishRender();

    public void drawCharacter(char character, int x, int y, Color backgroundColor, Color foregroundColor) {
        nativeDrawCharacter(character, x, y, backgroundColor.getColorCode(), foregroundColor.getColorCode());
    }
    public void drawText(String text, int x, int y, Color backgroundColor, Color foregroundColor) {
        nativeDrawText(text, x, y, backgroundColor.getColorCode(), foregroundColor.getColorCode());
    }

    public native void hideCursor();
    public native void showCursor();

    public native int getMaxTerminalHeight();
    public native int getMaxTerminalWidth();
}