function $(id) {
    return document.getElementById(id);
}

function createFormControlDataSet() {
    // A list of labelable elements resides in http://www.whatwg.org/specs/web-apps/current-work/multipage/forms.html#category-label
    var formControlClassNames = [
        'HTMLButtonElement',
        'HTMLDataListElement',
        'HTMLFieldSetElement',
        'HTMLInputElement',
        'HTMLKeygenElement',
        'HTMLLabelElement',
        'HTMLLegendElement',
        'HTMLMeterElement',
        'HTMLObjectElement',
        'HTMLOptGroupElement',
        'HTMLOptionElement',
        'HTMLOutputElement',
        'HTMLProgressElement',
        'HTMLSelectElement',
        'HTMLTextAreaElement'
    ];
    var formControlDataSet = {};
    for (var i = 0; i < formControlClassNames.length; i++) {
        var className = formControlClassNames[i];
        var tagName = className.toLowerCase().substring(4, className.length - 7);
        var element = document.createElement(tagName);
        formControlDataSet[tagName] = {
            inputType: null,
            isLabelable: true,
            isSupported: element.toString() == '[object ' + className + ']',
            name: tagName,
            tagName: tagName,
        };
    }
    formControlDataSet.datalist.isLabelable = false;
    formControlDataSet.fieldset.isLabelable = false;
    formControlDataSet.label.isLabelable = false;
    formControlDataSet.legend.isLabelable = false;
    formControlDataSet.object.isLabelable = false;
    formControlDataSet.optgroup.isLabelable = false;
    formControlDataSet.option.isLabelable = false;

    // Input type names reside in http://www.whatwg.org/specs/web-apps/current-work/multipage/the-input-element.html
    var inputTypeNames = [
        'button',
        'checkbox',
        'color',
        'date',
        'datetime',
        'datetime-local',
        'email',
        'file',
        'hidden',
        'image',
        'month',
        'number',
        'password',
        'radio',
        'range',
        'reset',
        'search',
        'submit',
        'tel',
        'text',
        'time',
        'url',
        'week',
    ];
    for (var i = 0; i < inputTypeNames.length; i++) {
        var typeName = inputTypeNames[i];
        var name = typeName + 'Type';
        var element = document.createElement('input');
        element.type = typeName;
        formControlDataSet[name] = {
            inputType: typeName,
            isLabelable: true,
            isSupported: element.type == typeName,
            name: name,
            tagName: 'input',
      };
    }
    formControlDataSet.hiddenType.isLabelable = false;

    return formControlDataSet;
}

function getValidationMessageBubbleNode(host) {
    // FIXME: We should search for a pseudo ID.
    return internals.shadowRoot(host).lastChild;
}

function getAbsoluteRect(element) {
    var rect = element.getBoundingClientRect();
    rect.top += document.body.scrollTop;
    rect.bottom += document.body.scrollTop;
    rect.left += document.body.scrollLeft;
    rect.right += document.body.scrollLeft;
    return rect;
}

function searchCancelButtonPosition(element) {
    var pos = {};
    pos.x = element.offsetLeft + element.offsetWidth - 9;
    pos.y = element.offsetTop + element.offsetHeight / 2;
    return pos;
}

function mouseMoveToIndexInListbox(index, listboxId) {
    var listbox = document.getElementById(listboxId);
    var itemHeight = Math.floor(listbox.offsetHeight / listbox.size);
    var border = 1;
    var y = border + index * itemHeight;
    if (window.eventSender)
        eventSender.mouseMoveTo(listbox.offsetLeft + border, listbox.offsetTop + y - window.pageYOffset);
}

function getUserAgentShadowTextContent(element) {
    return internals.youngestShadowRoot(element).textContent;
};
