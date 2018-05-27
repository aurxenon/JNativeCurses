package net.aurxenon.JNativeCurses.Input;

public enum KEYTYPE {
    KEY_ENTER(343), KEY_UP(259), KEY_RIGHT(261), KEY_LEFT(260), KEY_DOWN(258);

    private int numVal;

    KEYTYPE(int numVal) {
        this.numVal = numVal;
    }

    public int getNumVal() {
        return numVal;
    }
}