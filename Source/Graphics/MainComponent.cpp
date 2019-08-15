/*
  ==============================================================================

	MainComponent.cpp
	Created: 31 May 2019 9:12:52am
	Author:  Michael Jan

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(KeyRepeatAudioProcessor& p) :
	processor(p),
	bottomComponent(p),
	middleComponent(p),
	topComponent(p)
{
	addAndMakeVisible(bottomComponent);
	addAndMakeVisible(middleComponent);
	addAndMakeVisible(topComponent);
}

MainComponent::~MainComponent() {
}

void MainComponent::paint(Graphics& g) {
	g.setColour(MyLookAndFeel::GREY);
	g.fillAll();
}

void MainComponent::resized() {
	Rectangle<int> rect = getLocalBounds();
	topComponent.setBounds(rect.removeFromTop(rect.getHeight() * 2/11));
	middleComponent.setBounds(rect.removeFromTop(rect.getHeight() / 2));
	bottomComponent.setBounds(rect);
}

