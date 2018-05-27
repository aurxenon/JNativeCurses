package net.aurxenon.JNativeCurses;

import net.aurxenon.JNativeCurses.Display.Display;
import net.aurxenon.JNativeCurses.Input.Input;

public class TUI {
    private static Display display;
    private static Input input;

    static {
        System.loadLibrary("nativetui");
        display = new Display();
        input = new Input();
    }

    public TUI() {}

    public static Display displayObject() {return display;}
    public static Input inputObject() {return input;}
}