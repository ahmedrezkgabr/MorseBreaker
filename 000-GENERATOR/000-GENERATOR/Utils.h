#ifndef UTILS_H_
#define UTILS_H_

#define  READ_BIT(reg,bit)        ((reg>>bit)&1)
#define  SET_BIT(reg,bit)         (reg = reg |(1<<bit))
#define  CLEAR_BIT(reg,bit)       (reg = reg &~(1<<bit))
#define  TOGGLE_BIT(reg,bit)     (reg = reg ^(1<<bit))
#define  WRITE_BIT(reg,bit,value) (reg = (reg &~(1<<bit)) | (value<<bit) )


#endif /* UTILS_H_ */