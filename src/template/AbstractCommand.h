#pragma once

/**
 * コマンドの基底クラス
 */
class AbstractCommand
{
protected:
	/**
	 * コンストラクタ <br>
	 * AbstractCommand自体のインスタンス生成を防止
	 */
	AbstractCommand();

public:
	/**
	 * デストラクタ
	 */
	virtual ~AbstractCommand();

public:
	/**
	 * コマンド実行
	 */
	virtual void Execute() = 0;

	/**
	 * コマンド実行取消
	 */
	virtual void UnExecute() = 0;
};
