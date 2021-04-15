#include "AbstractReceiver.h"

/**
 * コンストラクタ <br>
 * AbstractCommand自体のインスタンス生成を防止
 */
AbstractReceiver::AbstractReceiver()
{

}

/**
 * デストラクタ
 */
AbstractReceiver::~AbstractReceiver()
{

}

/**
 * コマンドの実際動作を実行する。
 * @param 動作対象
 */
void AbstractReceiver::Operation(Object*)
{

}

/**
 * コマンドの実際動作を実行する。
 * @param 動作対象
 * @param 動作に必要な引数
 */
void AbstractReceiver::Operation(Object*, Arguments&)
{

}
