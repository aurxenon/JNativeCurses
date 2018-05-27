package net.aurxenon.JNativeCurses.Input;

public class Input {

    public Input(){}

    public native void inputInit();
    public native int readInput();

    public native void enableKeyDelay();
    public native void disableKeyDelay();

    public native void enableEcho();
    public native void disableEcho();

    public native void enableLongText();
    public native void disableLongText();
}
