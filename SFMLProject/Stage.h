#ifndef STAGE_H
#define STAGE_H

class Stage {
public:
	int rooms[3];
	bool firstStage = true, secondStage = false, thirdStage = false;
	Stage();
	void firstStageQuestion();
	~Stage();
};

#endif