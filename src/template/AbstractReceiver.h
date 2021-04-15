#pragma once

#include "Object.h"
#include "Arguments.h"

/**
 * Receiverの基底クラス
 */
class AbstractReceiver
{
protected:
	/**
	 * コンストラクタ <br>
	 * AbstractCommand自体のインスタンス生成を防止
	 */
	AbstractReceiver();

public:
	/**
	 * デストラクタ
	 */
	virtual ~AbstractReceiver();

public:
	/**
	 * コマンドの実際動作を実行する。
	 * @param 動作対象
	 */
	virtual void Operation(Object*);

	/**
	 * コマンドの実際動作を実行する。
	 * @param 動作対象
	 * @param 動作に必要な引数
	 */
	virtual void Operation(Object*, Arguments&);
};
