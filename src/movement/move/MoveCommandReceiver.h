#pragma once

#include "../../template/AbstractReceiver.h"

/**
 * 移動コマンドのレシーバー
 */
class MoveCommandReceiver : AbstractReceiver
{
public:
	/**
	 * コマンドの実際動作を実行する。
	 * @param 動作対象
	 * @param 動作に必要な引数
	 */
	void Operation(Object*, Arguments&) override;

	/**
	 * X方向に移動
	 * @param 移動対象
	 * @param 移動距離
	 */
	void MoveX(Object*, int);

	/**
	 * Y方向に移動
	 * @param 移動対象
	 * @param 移動距離
	 */
	void MoveY(Object*, int);
};
