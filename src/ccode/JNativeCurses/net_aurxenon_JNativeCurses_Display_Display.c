#include "net_aurxenon_JNativeCurses_Display_Display.h"

int maxX;
int maxY;
int colorPairCount = 0;

JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_displayInit(JNIEnv *env, jobject obj)
{
    initscr();
	Java_net_aurxenon_JNativeCurses_Display_Display_hideCursor(env, obj);
	start_color();

	//gotta add in a resize handler later on
	getmaxyx(stdscr, maxY, maxX);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_clearScreen(JNIEnv *env, jobject obj)
{
    clear();
    refresh();
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_nativeDrawCharacter(JNIEnv *env, jobject obj, jchar label, jint posX, jint posY, jint backgroundColor, jint foregroundColor)
{
    colorPairCount++;
    init_pair(colorPairCount, (int)foregroundColor, (int)backgroundColor);
    attron(COLOR_PAIR(colorPairCount));
    mvprintw((int)posY, (int)posX, &label);
    attroff(COLOR_PAIR(colorPairCount));
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_nativeDrawText(JNIEnv *env, jobject obj, jstring text, jint posX, jint posY, jint backgroundColor, jint foregroundColor)
{
    init_pair(colorPairCount, (int)foregroundColor, (int)backgroundColor);
    attron(COLOR_PAIR(colorPairCount));
    const char *utf_string = (*env)->GetStringUTFChars(env, text, 0);
    mvprintw((int)posY, (int)posX, utf_string);
    attroff(COLOR_PAIR(colorPairCount));
    (*env)->ReleaseStringUTFChars(env, text, utf_string);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_drawCursor(JNIEnv *env, jobject obj, jint posX, jint posY)
{
    move((int)posY, (int)posX);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_finishRender(JNIEnv *env, jobject obj)
{
    refresh();
    colorPairCount = 0;
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_hideCursor(JNIEnv *env, jobject obj)
{
    curs_set(0);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_showCursor(JNIEnv *env, jobject obj)
{
    curs_set(1);
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_refresh(JNIEnv *env, jobject obj)
{
    refresh();
}
JNIEXPORT void JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_exit(JNIEnv *env, jobject obj)
{
    endwin();
    refresh();
}
JNIEXPORT jint JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_getMaxTerminalHeight(JNIEnv *env, jobject obj)
{
    return (jint)maxY;
}
JNIEXPORT jint JNICALL Java_net_aurxenon_JNativeCurses_Display_Display_getMaxTerminalWidth(JNIEnv *env, jobject obj)
{
    return (jint)maxX;
}
