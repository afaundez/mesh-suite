#ifndef PREPROCESS_H
#define PREPROCESS_H

class PreProcess{

public:
    virtual ~PreProcess() {};
    virtual void execute() = 0;
};

#endif // PREPROCESS_H
