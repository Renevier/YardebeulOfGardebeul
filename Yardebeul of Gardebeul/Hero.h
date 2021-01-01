#pragma once
#include "Character.h"
class Hero :
    public Character
{
	//Variables
	float currentExp;
	float expNeed;
	float totalExp;

	int caracPoint;

private:
	virtual void InitVariable();
	void InitComponent(float _x, float _y, Texture& _texture_sheet);

public:
	Hero(float _x, float _y, Texture& _texture);
	~Hero();

	virtual void DisplayStats();
	void LevelProgress();
	void GainExp(float _exp);
	void LvlUp(vector<int> _arrayOfExp);
	void PickedUp();
	float TotalExpNeed();
	virtual void Update(const float& _dt);

	//Getter
	inline float GetCurrentExp() { return this->currentExp; };
	inline float GetExpNeed() { return this->expNeed; };
	inline float GetTotalExp() { return this->totalExp; };
	inline int GetCaracPoint() { return this->caracPoint; };
	inline AttributeComponent* GetAttributeComponent() { return this->attributeComponent; }

	//Setter
	inline void SetCurrentExp(float currentExp) { this->currentExp = currentExp; };
	inline void SetExpNeed(float expNeed) { this->expNeed = expNeed; };
	inline void SetTotalExp(float totalExp) { this->totalExp = totalExp; };
	inline void SetCaracPoint(int caracPoint) { this->caracPoint = caracPoint; };
};

