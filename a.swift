var someD = [
    "sedan" : [
        "TOYOTA" : [
            "2.5" : [
                "12"
            ]
        ],
        "HYUNDAI" : [
            "2.5" : [
                "12"
            ]
        ],
        "KIA" : [
            "2.5" : [
                "12"
            ]
        ],
        "TESLA" : [
            "2.5" : [
                "12"
            ]
        ],
        "PORSHE" : [
            "2.5" : [
                "12"
            ]
        ]
    ],
    "SVV" : [
        "TOYOTA" : [
            "3" : [
                "15"
            ],
            "3.5" : [
                "15"
            ],
            "4" : [
                "15"
            ]
        ],
        "HYUNDAI" : [
            "3" : [
                "15"
            ],
            "3.5" : [
                "15"
            ],
            "4" : [
                "15"
            ]
        ],
        "KIA" : [
            "3" : [
                "15"
            ],
            "3.5" : [
                "15"
            ],
            "4" : [
                "15"
            ]
        ],
        "TESLA" : [
            "3" : [
                "15"
            ],
            "3.5" : [
                "15"
            ],
            "4" : [
                "15"
            ]
        ],
        "PORSHE" : [
            "3" : [
                "15"
            ],
            "3.5" : [
                "15"
            ],
            "4" : [
                "15"
            ]
        ]
    ],
    "SPORT" : [
        
            "TOYOTA" : [
                "5.5" : [
                    "20"
                ],
                "6.0" : [
                    "20"
                ],
                "6.5" : [
                    "20"
                ],
                "7" : [
                    "20"
                ],
                "7.5" : [
                    "20"
                ],
                "8" : [
                    "20"
                ]
            ],
            "HYUNDAI" : [
                "5.5" : [
                    "20"
                ],
                "6.0" : [
                    "20"
                ],
                "6.5" : [
                    "20"
                ],
                "7" : [
                    "20"
                ],
                "7.5" : [
                    "20"
                ],
                "8" : [
                    "20"
                ]
            ],
            "KIA" : [
                "5.5" : [
                    "20"
                ],
                "6.0" : [
                    "20"
                ],
                "6.5" : [
                    "20"
                ],
                "7" : [
                    "20"
                ],
                "7.5" : [
                    "20"
                ],
                "8" : [
                    "20"
                ]
            ],
            "TESLA" : [
                "5.5" : [
                    "20"
                ],
                "6.0" : [
                    "20"
                ],
                "6.5" : [
                    "20"
                ],
                "7" : [
                    "20"
                ],
                "7.5" : [
                    "20"
                ],
                "8" : [
                    "20"
                ]
            ],
            "PORSHE" : [
                "5.5" : [
                    "20"
                ],
                "6.0" : [
                    "20"
                ],
                "6.5" : [
                    "20"
                ],
                "7" : [
                    "20"
                ],
                "7.5" : [
                    "20"
                ],
                "8" : [
                    "20"
                ]
            ]
        
    ]
]


func getUserInput(prompt: String) -> String? {
    print(prompt, terminator: "")
    return readLine()
}


func getUserChoice(options: [String]) -> Int? {
    for (index, option) in options.enumerated() {
        print("\(index + 1). \(option)")
    }
    
    if let choiceString = getUserInput(prompt: "Enter your choice: "),
       let choice = Int(choiceString) {
        return choice
    } else {
        print("Invalid choice. Please try again.")
        return nil
    }
}

var selectedCategory: String?
var selectedBrand: String?
var selectedModel: String?


print("Select a category:")
if let categoryChoice = getUserChoice(options: Array(someD.keys)) {
    selectedCategory = Array(someD.keys)[categoryChoice - 1]
    
    print("Select a brand:")
    if let brandChoice = getUserChoice(options: Array(someD[selectedCategory!]!.keys)) {
        selectedBrand = Array(someD[selectedCategory!]!.keys)[brandChoice - 1]
        
        print("Select a model:")
        if let modelChoice = getUserChoice(options: Array(someD[selectedCategory!]![selectedBrand!]!.keys)) {
            selectedModel = Array(someD[selectedCategory!]![selectedBrand!]!.keys)[modelChoice - 1]
            var x = 0
            if selectedCategory == "sedan"{
                x = 12
            } else if selectedCategory == "sedan"{
                x = 15
            } else{
                x = 20
            }
            print("You selected: \(selectedCategory!) - \(selectedBrand!) - \(selectedModel!) - \(x)");
            

        }
    }
}

