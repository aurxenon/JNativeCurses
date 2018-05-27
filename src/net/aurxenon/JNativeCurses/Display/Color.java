package net.aurxenon.JNativeCurses.Display;

import java.util.HashMap;
import java.util.Map;

public enum Color {
    BLACK(0),
    RED(1),
    GREEN(2),
    YELLOW(3),
    BLUE(4),
    MAGENTA(5),
    CYAN(6),
    WHITE(7);

    private final int colorCode;
    private static Map<Integer, Color> map = new HashMap<Integer, Color>();

    static {
        for (Color colorEnum : Color.values()) {
            map.put(colorEnum.getColorCode(), colorEnum);
        }
    }

    Color(int colorCode) {
        this.colorCode = colorCode;
    }

    public int getColorCode() {
        return colorCode;
    }

    public static Color valueOf(int colorCode) {
        return map.get(colorCode);
    }
}
