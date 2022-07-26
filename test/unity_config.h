#ifndef UNITY_CONFIG_H_
#define UNITY_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

void unityOutputStart();
void unityOutputChar(char);
void unityOutputFlush();
void unityOutputComplete();

#define UNITY_OUTPUT_START() unityOutputStart()
#define UNITY_OUTPUT_CHAR(c) unityOutputChar(c)
#define UNITY_OUTPUT_FLUSH() unityOutputFlush()
#define UNITY_OUTPUT_COMPLETE() unityOutputComplete()

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* UNITY_CONFIG_H_ */
