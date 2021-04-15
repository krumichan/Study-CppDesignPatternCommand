#pragma once

#include "../../template/Arguments.h"

/**
 * 移動に必要な引数クラス
 */
class MoveArgs : public Arguments
{
public:
	/**
	 * 移動方向
	 */
	typedef enum {
		UP    //!< UP 上
		,DOWN //!< DOWN　下
		,LEFT //!< LEFT　左
		,RIGHT//!< RIGHT　右
		,
	} MoveDirection;

public:
	/**
	 * 移動方向
	 */
	MoveDirection direction;

	/**
	 * 移動距離
	 */
	float distance;
};
